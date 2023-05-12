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

int is_func(char *data, node **stack, int idx) {
  int status = ERR;
  if (strstr(data, "sin")) {
    if (stack) {
      push_back(*stack, 1, data[idx]);
    } else {
      create_node(*&stack, 1, data[idx]);
    }
    status = OK;
  } else if (strstr(data, "cos")) {
    status = OK;
  }
  return status;
}