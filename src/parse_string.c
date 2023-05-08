#include "parse_string.h"

#include "s21_helper.h"

int parse_string(char *data) {
  node stack;
  int status = OK;
  if (data) {
    int len = len_data(data), idx, jdx;
    char *parsed_string = (char *)malloc(sizeof(char)*len);
    for (idx = 0, jdx = 0; idx < len; ++idx) {
      if (if_digit(data[idx])) {
        parsed_string[jdx] = data[idx];
        ++jdx;
      }
    }
  } else {
    status = ERR;
  }
  return status;
}
