#ifndef SRC_S21_HELPER_H_
#define SRC_S21_HELPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "math.h"

enum status { ERR, OK };
enum prior { BR, P_M, M_D, POW, SIN };

#include "stack.h"

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
int numbers(char *p, char *notation, int *jdx, int *idx);
int check_brakets(char *p);
void add_stack_last(node **stack, char *notation, int *jdx, int *pr, char *b);
int check_first(const char *data);
int check_correct_string(const char *data);
int check_correct_oper(const char *data);
int check_trig(char c);
int check_last_sym(const char *data);
int cor_oper_num(char c);
int check_unar(char c);
void add_zero_notation(char *notation, int *jdx);
int check_plus_min(const char *data);

#endif  //  SRC_S21_HELPER_H_
