#include "parse_string.h"

// #include <stdio.h>

int main(void) {
  char *data = "0+asin(X)*sin(X)";
  char *notation = (char *)malloc(sizeof(char) * len_data(data));
  int status = parse_string(data, notation);
  printf("data = %s\n", data);
  printf("status = %d\n", status);
  printf("notation = %s\n", notation);
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
        if (stack) {
          push_back(stack, high, *p);
        } else {
          create_node(&stack, high, *p);
        }
        status = OK;
      }  else if ('*' == *p || '/' == *p || '%' == *p) {
          if (stack) {
            push_back(stack, mid, *p);
          } else {
            create_node(&stack, mid, *p);
          }
          status = OK;
      } else if ('+' == *p || '-' == *p) {
        if (stack) {
          push_back(stack, low, *p);
        } else {
          create_node(&stack, low, *p);
        }
        status = OK;
      } else if ('s' == *p || 'c' == *p || 'a' == *p ||
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
  return status;
}