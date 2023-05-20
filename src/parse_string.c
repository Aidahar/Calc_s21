#include "parse_string.h"

int main(void) {
  char data[256] = "(5+5)^6";
  char *notation = (char *)calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  printf("data = %s\n", data);
  printf("status = %d\n", status);
  print_notion(notation);
  free(notation);
  return 0;
}

int parse_string(char *data, char *notation) {
  struct Node *stack = NULL;
  int status = ERR;
  if (data) {
    int jdx, idx, pr, i;
    int len = len_data(data);
    char b;
    // char *p;
    for (i= 0, jdx = 0; i < len; ++idx, ++i) {
      if (is_digit(data[i]) || data[i] == '.') {
        notation[jdx] = data[i];
        notation[++jdx] = ' ';
        ++jdx;
        status = OK;
      } else if ('(' == data[i]) {
        add_stack(&stack, data[i], BR);
        status = OK;
      } else if ('+' == data[i] || '-' == data[i]) {
        if (stack) {
          pop_prior(&stack, &pr);
          if (pr >= P_M) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            ++jdx;
          }
        }
        add_stack(&stack, data[i], P_M);
        status = OK;
      } else if ('*' == data[i] || '/' == data[i] || '%' == data[i]) {
        if (stack) {
          pop_prior(&stack, &pr);
          if (pr >= M_D) {
            pop_back(&stack, &pr, &b);
            notation[jdx] = b;
            ++jdx;
          }
        }
        add_stack(&stack, data[i], M_D);
        status = OK;
      } else if ('^' == data[i]) {
        if (stack) {
          if (stack->prior) {
          }
        }
        add_stack(&stack, data[i], POW);
        status = OK;
      } else if ('s' == data[i] || 'c' == data[i] || 'a' == data[i] || 't' == data[i] ||
                 'l' == data[i]) {
        if (is_func(data, &stack, &idx)) {
          for (; 1 < idx; --idx, ++data) {
          }
          status = OK;
        } else {
          status = ERR;
        }
      } else if (')' == data[i]) {
        pop_back(&stack, &pr, &b);
        if (b != '(') {
          notation[jdx] = b;
          ++jdx;
        }
        while ('(' != b) {
          pop_back(&stack, &pr, &b);
          if (b != '(') {
            notation[jdx] = b;
            ++jdx;
          }
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
    while (!check_stack(&stack)) {
      pop_back(&stack, &pr, &b);
      notation[jdx] = b;
      ++jdx;
    }
  }
  print_list(stack);
  free_node(stack);
  return status;
}