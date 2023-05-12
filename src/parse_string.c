#include "parse_string.h"

// #include "s21_helper.h"
// #include "stack.h"
#include <stdio.h>

int main(void) {
  char *data = "0+sin(X)";
  char *notation = (char *)malloc(sizeof(char) * len_data(data));
  int status = parse_string(data, notation);
  printf("data = %s\n", data);
  printf("status = %d\n", status);
  printf("notation = %s\n", notation);
  return 0;
}

int parse_string(char *data, char *notation) {
  node *stack = NULL;
  int status = OK;
  if (data) {
    int len = len_data(data), idx, jdx;
    for (idx = 0, jdx = 0; idx < len; ++idx) {
      if (is_digit(data[idx])) {
        notation[jdx] = data[idx];
        ++jdx;
      } else if ('(' == data[idx]) {
        if (stack) {
          push_back(stack, 2, data[idx]);
        } else {
          create_node(&stack, 2, data[idx]);
        }
      } else if ('*' == data[idx] || '/' == data[idx] || '%' == data[idx]) {
        if (stack) {
          push_back(stack, 1, data[idx]);
        } else {
          create_node(&stack, 1, data[idx]);
        }
      } else if ('+' == data[idx] || '-' == data[idx]) {
        if (stack) {
          push_back(stack, 0, data[idx]);
        } else {
          create_node(&stack, 0, data[idx]);
        }
      } else if ('s' == data[idx] || 'c' == data[idx] || 'a' == data[idx] ||
                 't' == data[idx] || 'l' == data[idx]) {
        if (is_func(data, &stack, idx)) {
          // if (stack) {
          //   push_back(stack, 1, data[idx]);
          // } else {
          //   create_node(&stack, 1, data[idx]);
          // }
        }
      }
    }
  } else {
    status = ERR;
  }
  print_list(stack);
  return status;
}
