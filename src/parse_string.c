#include "parse_string.h"

int main(void) {
  char data[256] = "(222*2.22 + 1.2)-1/2*(2^2-2)";
  if (check_brackets(data)) {
    char *notation = calloc(sizeof(char), len_data(data) * 2);
    int status = parse_string(data, notation);
    if (status == OK) {
      printf("data = %s\n", data);
      print_notation(notation);
    } else {
      printf("ERROR MOTHERFUCKER!\n");
    }
    free(notation);
  }
  return 0;
}

int parse_string(char *data, char *notation) {
  int status = ERR;
  if (data) {
    struct Node *stack = NULL;
    int jdx, idx, pr;
    char b;
    char *p;
    for (p = data, jdx = 0; *p; ++idx, ++p) {
      if (is_digit(*p) || *p == '.') {
        int k = 0;
        if (check_numbers(p, notation, &jdx, &k)) {
          notation[jdx] = ' ';
          ++jdx;
          for (; 1 < k; --k, ++p) {
          }
          status = OK;
        } else {
          status = ERR;
          break;
        }
      } else if ('(' == *p) {
        push_back(&stack, BR, *p);
        status = OK;
      } else if ('+' == *p || '-' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          while (pr >= P_M && !check_stack(stack)) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            notation[++jdx] = ' ';
            ++jdx;
            pop_prior(stack, &pr);
          }
        }
        push_back(&stack, P_M, *p);
        status = OK;
      } else if ('*' == *p || '/' == *p || '%' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          while (pr >= M_D && !check_stack(stack)) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            notation[++jdx] = ' ';
            ++jdx;
            pop_prior(stack, &pr);
          }
        }
        push_back(&stack, M_D, *p);
        status = OK;
      } else if ('^' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          while (pr >= POW && !check_stack(stack)) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            notation[++jdx] = ' ';
            ++jdx;
            pop_prior(stack, &pr);
          }
        }
        push_back(&stack, POW, *p);
        status = OK;
      } else if ('s' == *p || 'c' == *p || 'a' == *p || 't' == *p ||
                 'l' == *p) {
        if (is_func(p, &stack, &idx)) {
          for (; 1 < idx; --idx, ++p) {
          }
          status = OK;
        } else {
          status = ERR;
        }
      } else if (')' == *p) {
        pop_back(&stack, &pr, &b);
        if ('(' != b) {
          notation[jdx] = b;
          notation[++jdx] = ' ';
          ++jdx;
          while ('(' != b) {
            pop_back(&stack, &pr, &b);
            if (b != '(') {
              notation[jdx] = b;
              notation[++jdx] = ' ';
              ++jdx;
            }
          }
        }
        status = OK;
      }
      idx = 0;
    }
    if (status == OK) {
      while (!check_stack(stack)) {
        pop_back(&stack, &pr, &b);
        notation[jdx] = b;
        notation[++jdx] = ' ';
        ++jdx;
      }
    }
    // print_list(stack);
    free_node(&stack);
  }
  return status;
}