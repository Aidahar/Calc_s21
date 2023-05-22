#ifndef SRC_S21_HELPER_H_
#define SRC_S21_HELPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse_string.h"
#include "stack.h"

enum status { ERR, OK };
enum prior { BR, P_M, M_D, POW, SIN };
// enum fun { SIN, COS, TAN, ASIN, ACOS, ATAN, SQRT, LN, LOG };

int is_digit(char data);
int len_data(char *data);
void print_notion(char *data);
int is_func(char *data, struct Node **stack, int *idx);

#endif  // SRC_S21_HELPER_H_