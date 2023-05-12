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

int is_func(char *data, node **stack, int *idx) {
  int status = ERR;
  if ('a' == *data) {
    if (strstr(data, "asin")) {
      if (stack) {
        push_back(*stack, 1, 'S');
      } else {
        create_node(*&stack, 1, 'S');
      }
      *idx = 4;
      status = OK;
    } else if (strstr(data, "acos")) {
      if (stack) {
        push_back(*stack, 1, 'C');
      } else {
        create_node(*&stack, 1, 'C');
      }
      *idx = 4;
      status = OK;
    } else if (strstr(data, "asin")) {
      if (stack) {
        push_back(*stack, 1, 'S');
      } else {
        create_node(*&stack, 1, 'S');
      }
      *idx = 4;
      status = OK;
    }  else if (strstr(data, "acos")) {
      if (stack) {
        push_back(*stack, 1, 'C');
      } else {
        create_node(*&stack, 1, 'C');
      }
      *idx = 4;
      status = OK;
    }  else if (strstr(data, "atan")) {
    if (stack) {
      push_back(*stack, 1, 'T');
    } else {
      create_node(*&stack, 1, 'T');
    }
      *idx = 4;
      status = OK;
    }
  } else {
    if (strstr(data, "sin")) {
      if (stack) {
        push_back(*stack, 1, 's');
      } else {
        create_node(*&stack, 1, 's');
      }
      *idx = 3;
      status = OK;
    } else if (strstr(data, "cos")) {
      if (stack) {
        push_back(*stack, 1, 'c');
      } else {
        create_node(*&stack, 1, 'c');
      }
      *idx = 3;
      status = OK;
    } else if (strstr(data, "tan")) {
      if (stack) {
        push_back(*stack, 1, 't');
      } else {
        create_node(*&stack, 1, 't');
      }
      *idx = 3;
      status = OK;
    } else if (strstr(data, "sqrt")) {
      if (stack) {
        push_back(*stack, 1, 'q');
      } else {
        create_node(*&stack, 1, 'q');
      }
      *idx = 4;
      status = OK;
    } else if (strstr(data, "ln")) {
      if (stack) {
        push_back(*stack, 1, 'l');
      } else {
        create_node(*&stack, 1, 'l');
      }
      *idx = 2;
      status = OK;
    } else if (strstr(data, "log")) {
      if (stack) {
        push_back(*stack, 1, 'L');
      } else {
        create_node(*&stack, 1, 'L');
      }
      *idx = 3;
      status = OK;
    }
  }
  return status;
}