#ifndef SRC_STACK_H
#define SRC_STACK_H

typedef struct Node {
  int prior;
  char symb;
  struct Node *next;
} node;

#include "s21_helper.h"

int create_node(node **patr, int prior, char b);
void push_back(node **patr, int prior, char b);
void pop_back(node **patr, int *prior, char *b);
void free_node(node **patr);
void print_list(node *patr);
void add_stack(node **stack, char data, int prior);
int check_stack(node **stack);
void pop_prior(node **patr, int *prior);

#endif  // SRC_STACK_H