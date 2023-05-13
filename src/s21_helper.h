#ifndef SRC_S21_HELPER_H_
#define SRC_S21_HELPER_H_

#include "stack.h"
#include "parse_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum status { ERR, OK };
enum prior { low, mid, high };
enum fun { SIN, COS, TAN, ASIN, ACOS, ATAN, SQRT, LN, LOG };

int is_digit(char data);
int len_data(char *data);
void print_notion(char *data);
int is_func(char *data, node **stack, int *idx);

#endif  // SRC_S21_HELPER_H_