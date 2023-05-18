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
  while (*data != '\0') {
    printf("%c", *data);
    ++data;
  }
  printf("\n");
}

int is_func(char *data, node **stack, int *idx) {
  int status = OK;
  char *tmp = calloc(sizeof(char), 4);
  int id;
  for (id = 0; id < 4; ++id, ++data) {
    tmp[id] = *data;
  }
  if ('a' == *data) {
    if (strstr(tmp, "asin")) {
      add_stack(stack, 'S', 1);
      *idx = 4;
    } else if (strstr(tmp, "acos")) {
      add_stack(stack, 'C', 1);
      *idx = 4;
    } else if (strstr(tmp, "atan")) {
      add_stack(stack, 'T', 1);
      *idx = 4;
    }
  } else if ('s' == *tmp || 'c' == *tmp || 't' == *tmp || 'l' == *tmp) {
    if (strstr(tmp, "sin")) {
      add_stack(stack, 's', 1);
      *idx = 3;
    } else if (strstr(tmp, "cos")) {
      add_stack(stack, 'c', 1);
      *idx = 3;
    } else if (strstr(tmp, "tan")) {
      add_stack(stack, 't', 1);
      *idx = 3;
    } else if (strstr(tmp, "sqrt")) {
      add_stack(stack, 'q', 1);
      *idx = 4;
    } else if (strstr(tmp, "ln")) {
      add_stack(stack, 'l', 1);
      *idx = 2;
    } else if (strstr(tmp, "log")) {
      add_stack(stack, 'L', 1);
      *idx = 3;
    }
  } else {
    status = ERR;
  }
  free(tmp);
  return status;
}
