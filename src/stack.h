#ifndef SRC_STACK_H
#define SRC_STACK_H

#include "s21_helper.h"

typedef struct Node {
  int token;
  struct Node *next;
} node;

int create_node(node **patr, int token);
void push_back(node **patr, int token);
void free_node(node *patr);

#endif  // SRC_STACK_H