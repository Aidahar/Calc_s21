#ifndef SRC_STACK_H
#define SRC_STACK_H

typedef struct Node {
  int prior;
  char symb;
  struct Node *next;
} node;

#include "s21_helper.h"

int push_back(node **patr, int prior, char symb);
void pop_back(node **patr, int *prior, char *symb);
void free_node(node **patr);
void print_list(node *patr);
int check_stack(const node *stack);
void pop_prior(const node *patr, int *prior);
void add_stack(node **patr, char *notation, int *jdx, int op);

#endif  // SRC_STACK_H