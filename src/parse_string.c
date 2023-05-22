#include "parse_string.h"

int main(void) {
  char data[256] = "(5+2)^6";
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  printf("data = %s\n", data);
  printf("status = %d\n", status);
  print_notion(notation);
  free(notation);
  notation = NULL;
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
        add_stack(&stack, *p, BR);
        status = OK;
      } else if ('+' == *p || '-' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          if (pr >= P_M) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            ++jdx;
          }
        }
        add_stack(&stack, *p, P_M);
        status = OK;
      } else if ('*' == *p || '/' == *p || '%' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          if (pr >= M_D) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            ++jdx;
          }
        }
        add_stack(&stack, *p, M_D);
        status = OK;
      } else if ('^' == *p) {
        if (stack) {
          pop_prior(stack, &pr);
          if (pr >= POW) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            ++jdx;
          }
        }
        add_stack(&stack, *p, POW);
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
          ++jdx;
          if ('(' == b) {
            pop_back(&stack, &pr, &b);
          }
          while ('(' != b) {
            pop_back(&stack, &pr, &b);
            if (b != '(') {
              notation[jdx] = b;
              ++jdx;
            }
          }
        } else if ('(' == b) {
          pop_back(&stack, &pr, &b);
        }
        if (pr == 1) {
          pop_back(&stack, &pr, &b);
          notation[jdx] = b;
          ++jdx;
        }
        status = OK;
      }
      idx = 0;
    }
    while (!check_stack(stack)) {
      pop_back(&stack, &pr, &b);
      notation[jdx] = b;
      ++jdx;
    }
    print_list(stack);
    free_node(&stack);
  }
  return status;
}