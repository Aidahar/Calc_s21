#ifndef SRC_STACK_H
#define SRC_STACK_H

typedef struct Node {
  int prior;
  char symb;
  struct Node *next;
} node;

typedef struct double_node {
  double val;
  struct double_node *next;
} double_node;

#include "s21_helper.h"

int push_back(node **patr, int prior, char symb);
void pop_back(node **patr, int *prior, char *symb);
void free_node(node **patr);
void print_list(node *patr);
int check_stack(const node *stack);
void pop_prior(const node *patr, int *prior);
void add_stack(node **patr, char *notation, int *jdx, int op);
int push_back_dnode(double_node **patr, double data);
void pop_back_double(double_node **patr, double *num);
void print_double_list(double_node *patr);

#endif  // SRC_STACK_H