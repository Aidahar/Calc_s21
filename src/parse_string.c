#include "parse_string.h"

#include "s21_helper.h"

int parse_string(char *data) {
  node stack;
  int status = OK;
  if (data) {
    int len = len_data(data), idx;
    for (idx = 0; idx < len; ++idx) {
      if (if_digit(data[idx])) {
      }
    }
  } else {
    status = ERR;
  }
  return status;
}
