#ifndef SRC_S21_HELPER_H_
#define SRC_S21_HELPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse_string.h"
#include "stack.h"

enum status { ERR, OK };
enum prior { low, mid, high };
enum fun { SIN, COS, TAN, ASIN, ACOS, ATAN, SQRT, LN, LOG };

int is_digit(char data);
int len_data(char *data);
int is_fun(char *data);

#endif  // SRC_S21_HELPER_H_