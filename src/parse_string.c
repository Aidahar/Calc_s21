#include "parse_string.h"

#include "s21_helper.h"

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
  node stack;
  int status = OK;
  if (data) {
    int len = len_data(data), idx, jdx;
    for (idx = 0, jdx = 0; idx < len; ++idx) {
      if (is_digit(data[idx])) {
        notation[jdx] = data[idx];
        ++jdx;
      } else if ('(' == data[idx]) {
        create_node(&stack, 1, data[idx]);
      }
    }
  } else {
    status = ERR;
  }
  return status;
}
