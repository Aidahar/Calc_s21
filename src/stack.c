#include "stack.h"

int main(void) {
  int prior;
  char sym;
  node *test = NULL;
  create_node(&test, low, '+');
  push_back(&test, high, '(');
  push_back(&test, high, ')');
  push_back(&test, mid, '*');
  pop_back(&test, &prior, &sym);
  printf("prior = %d, symbol = %c\n", prior, sym);
  pop_back(&test, &prior, &sym);
  printf("prior = %d, symbol = %c\n", prior, sym);
  free_node(test);
  return 0;
}

int create_node(node **patr, int prior, char b) {
  int status = OK;
  node *tmp = (node *)malloc(sizeof(node));
  if (NULL == tmp) {
    status = ERR;
  } else {
    tmp->prior = prior;
    tmp->symb = b;
    tmp->next = NULL;
    (*patr) = tmp;
  }
  return status;
}

void push_back(node **patr, int prior, char b) {
  node *new = NULL;
  create_node(&new, prior, b);
  node *cur = *patr;
  while (NULL != cur->next) {
    cur = cur->next;
  }
  cur->next = new;
}

void pop_back(node **patr, int *prior, char *b) {
  node *tmp = *patr;
  while (NULL != tmp->next->next) {
    tmp = tmp->next;
  }
  *prior = tmp->prior;
  *b = tmp->symb;
  tmp = NULL;
}

void free_node(node *patr) {
  node *p = patr;
  while (NULL != p) {
    p = patr->next;
    free(patr);
    patr = p;
  }
}

void print_list(node *patr) {
  while (NULL != patr) {
    printf("priority %d ", patr->prior);
    printf("symbol %c\n", patr->symb);
    patr = patr->next;
  }
}