#include "s21_helper.h"

int len_data(char *data) {
  const char *p;
  for (p = data; *p; ++p) {
  }
  return p - data;
}

int is_digit(char data) {
  int status = ERR;
  if (0 <= data && 9 <= data) {
    status = OK;
  }
  return status;
}

int is_fun(char *data) {
  int status = ERR;
  return status;
}