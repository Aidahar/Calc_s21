#ifndef SRC_S21_HELPER_H_
#define SRC_S21_HELPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse_string.h"
#include "stack.h"

enum status { ERR, OK };
enum prior { BR, P_M, M_D, POW, SIN };

int is_digit(char data);
int len_data(const char *data);
void print_notation(char *data);
int is_func(char *data, struct Node **stack, int *idx);
int check_brackets(const char *data);
void pop_br(char *stack_br, int *top);
void push_br(char *stack_br, char br, int *top);
void peek(const char *stack_br, char *br, int top);
int check_numbers(const char *data, char *notation, int *jdx, int *idx);
void add_notation(char *notation, int *jdx, char sym);

#endif  //  SRC_S21_HELPER_H_