#include "s21_helper.h"

int len_data(char *data) {
  const char *p;
  for (p = data; *p; ++p) {
  }
  return p - data;
}

int is_digit(char data) {
  int status = ERR;
  if (48 <= data && data <= 57) {
    status = OK;
  }
  return status;
}

void print_notion(char *data) {
  while(*data != '\0') {
    printf("%c", *data);
    ++data;
  }
  printf("\n");
}

int is_func(char *data, node **stack, int *idx) {
  int status = OK;
  if ('a' == *data) {
    if (strstr(data, "asin")) {
      add_stack(stack, 'S', 1);
      *idx = 4;
    } else if (strstr(data, "acos")) {
      add_stack(stack, 'C', 1);
      *idx = 4;
    } else if (strstr(data, "atan")) {
      add_stack(stack, 'T', 1);
      *idx = 4;
    }
  } else if ('s' == *data || 'c' == *data || 't' == *data || 'l' == *data) {
    if (strstr(data, "sin")) {
      add_stack(stack, 's', 1);
      *idx = 3;
    } else if (strstr(data, "cos")) {
      add_stack(stack, 'c', 1);
      *idx = 3;
    } else if (strstr(data, "tan")) {
      add_stack(stack, 't', 1);
      *idx = 3;
    } else if (strstr(data, "sqrt")) {
      add_stack(stack, 'q', 1);
      *idx = 4;
    } else if (strstr(data, "ln")) {
      add_stack(stack, 'l', 1);
      *idx = 2;
    } else if (strstr(data, "log")) {
      add_stack(stack, 'L', 1);
      *idx = 3;
    }
  } else {
    status = ERR;
  }
  return status;
}
