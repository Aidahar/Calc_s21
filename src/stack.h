#ifndef SRC_STACK_H
#define SRC_STACK_H

#include "s21_helper.h"

typedef struct Node {
  int prior;
  char symb;
  struct Node *next;
} node;

int create_node(node **patr, int prior, char b);
void push_back(node *patr, int prior, char b);
void pop_back(node *patr, int *prior, char *b);
void free_node(node *patr);
void print_list(node *patr);
void add_stack(node **stack, char data, int prior);

#endif // SRC_STACK_H