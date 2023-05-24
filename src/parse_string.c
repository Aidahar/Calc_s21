#include "parse_string.h"

int main(void) {
  char data[256] = "sin(2-cos(3+5))*(5+2)^6";
  int check = check_brackets(data);
  printf("CHECKING FUNCTION = %d\n", check);
  // char *notation = calloc(sizeof(char), len_data(data) * 2);
  // int status = parse_string(data, notation);
  // printf("data = %s\n", data);
  // printf("status = %d\n", status);
  // print_notation(notation);
  // free(notation);
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
        notation[jdx] = *p;
        notation[++jdx] = ' ';
        ++jdx;
        status = OK;
      } else if ('(' == *p) {
        push_back(&stack, BR, *p);
        status = OK;
      } else if ('+' == *p || '-' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          if (pr >= P_M) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            notation[++jdx] = ' ';
            ++jdx;
          }
        }
        push_back(&stack, P_M, *p);
        status = OK;
      } else if ('*' == *p || '/' == *p || '%' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          if (pr >= M_D) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            notation[++jdx] = ' ';
            ++jdx;
          }
        }
        push_back(&stack, M_D, *p);
        status = OK;
      } else if ('^' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          if (pr >= POW) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            notation[++jdx] = ' ';
            ++jdx;
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
    while (!check_stack(stack)) {
      pop_back(&stack, &pr, &b);
      notation[jdx] = b;
      notation[++jdx] = ' ';
      ++jdx;
    }
    print_list(stack);
    free_node(&stack);
  }
  return status;
}