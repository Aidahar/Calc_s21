#include "parse_string.h"

// #include <stdio.h>

int main(void) {
  char *data = "(1+2)*(2*3)";
  char *notation = (char *)calloc(sizeof(char), len_data(data));
  int status = parse_string(data, notation);
  printf("data = %s\n", data);
  printf("status = %d\n", status);
  print_notion(notation);
  free(notation);
  return 0;
}

int parse_string(char *data, char *notation) {
  node *stack = NULL;
  int status = ERR;
  if (data) {
    int jdx, idx;
    char *p;
    for (p = data, jdx = 0; *p; ++idx, ++p) {
      if (is_digit(*p)) {
        notation[jdx] = *p;
        ++jdx;
        status = OK;
      }  else if ('(' == *p) {
        add_stack(&stack, *p, L_BR);
        status = OK;
      }  else if ('*' == *p || '/' == *p || '%' == *p) {
        add_stack(&stack, *p, M_D);
        status = OK;
      }  else if ('+' == *p || '-' == *p) {
        add_stack(&stack, *p, P_M);
        status = OK;
      }  else if ('s' == *p || 'c' == *p || 'a' == *p ||
                 't' == *p || 'l' == *p) {
        if (is_func(p, &stack, &idx)) {
          for(;1 < idx ; --idx, ++p) {
          }
          status = OK;
        }
      } else if (')' == *p) {
        int pr;
        char b;
        pop_back(&stack, &pr, &b);
        notation[jdx] = b;
        ++jdx;
        while ('(' != b) {
          pop_back(&stack, &pr, &b);
          if (b != '(') {
            notation[jdx] = b;
            ++jdx;
          }
        }
        // ++jdx;
        status = OK;
      }
      idx = 0;
    }
  }
  print_list(stack);
  free_node(stack);
  return status;
}