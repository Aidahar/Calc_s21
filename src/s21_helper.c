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

int is_func(char *data, struct Node **stack, int *idx) {
  int status = OK, id;
  char *tmp = calloc(sizeof(char), 5);
  for (id = 0; id < 4; ++id, ++data) {
    tmp[id] = *data;
  }
  tmp[4] = '\0';
  if ('a' == *tmp) {
    if (strstr(tmp, "asin") != NULL) {
      add_stack(stack, 'S', POW);
      *idx = 4;
    } else if (strstr(tmp, "acos") != NULL) {
      add_stack(stack, 'C', POW);
      *idx = 4;
    } else if (strstr(tmp, "atan") != NULL) {
      add_stack(stack, 'T', POW);
      *idx = 4;
    }
  } else if ('s' == *tmp || 'c' == *tmp || 't' == *tmp || 'l' == *tmp) {
    if (strstr(tmp, "sin") != NULL) {
      add_stack(stack, 's', POW);
      *idx = 3;
    } else if (strstr(tmp, "cos") != NULL) {
      add_stack(stack, 'c', POW);
      *idx = 3;
    } else if (strstr(tmp, "tan") != NULL) {
      add_stack(stack, 't', POW);
      *idx = 3;
    } else if (strstr(tmp, "sqrt") != NULL) {
      add_stack(stack, 'q', POW);
      *idx = 4;
    } else if (strstr(tmp, "ln") != NULL) {
      add_stack(stack, 'l', POW);
      *idx = 2;
    } else if (strstr(tmp, "log") != NULL) {
      add_stack(stack, 'L', POW);
      *idx = 3;
    }
    free(tmp);
    tmp = NULL;
  } else {
    status = ERR;
  }
  return status;
}
