#ifndef SRC_STACK_H
#define SRC_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum status { ERR, OK };

typedef struct Node {
  int token;
  struct Node *next;
} node;

int create_node(node **patr, int token);
void push_back(node **patr, int token);
void free_node(node **patr);

#endif  // SRC_STACK_H