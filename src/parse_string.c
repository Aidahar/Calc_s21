#include "parse_string.h"

// #include <stdio.h>

int main(void) {
  char *data = "0+asin(X)*2*sin(X)";
  char *notation = (char *)malloc(sizeof(char) * len_data(data));
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
        add_stack(&stack, *p, high);
        status = OK;
      }  else if ('*' == *p || '/' == *p || '%' == *p) {
        add_stack(&stack, *p, mid);
        status = OK;
      }  else if ('+' == *p || '-' == *p) {
        add_stack(&stack, *p, low);
        status = OK;
      }  else if ('s' == *p || 'c' == *p || 'a' == *p ||
                 't' == *p || 'l' == *p) {
        if (is_func(p, &stack, &idx)) {
          for(;1 < idx ; --idx, ++p) {
          }
          status = OK;
        }
      }
      idx = 0;
    }
  }
  print_list(stack);
  free_node(stack);
  return status;
}