#include "stack.h"

int create_node(node **patr, int token) {
  int status = OK;
  node *tmp = (node *)malloc(sizeof(node));
  if (NULL == tmp) {
    status = ERR;
  } else {
    tmp->token = strdup(token);
    tmp->next = NULL;
    (*patr) = tmp;
  }
}

void push_back(node **patr, int token) {
  node *new = NULL;
  create(&new, token);
  node *cur = patr;
  while (NULL != cur->next) {
    cur = cur->next;
  }
  cur->next = new;
}

void print_list(node *patr) {
  while (NULL != patr) {
    printf("%s\n", patr->token);
    patr = patr->next;
  }
}

void free_node(node *patr) {
  node *p = patr;
  while (NULL != p) {
    p = patr->next;
    free(patr->token);
    free(patr);
    patr = p;
  }
}