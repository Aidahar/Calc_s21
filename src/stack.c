#include "stack.h"

// int main(void) {
//   int prior;
//   char sym;
//   node *test = NULL;
//   create_node(&test, low, '+');
//   push_back(test, high, '(');
//   push_back(test, high, ')');
//   push_back(test, mid, '*');
//   printf("all stack\n");
//   print_list(test);
//   printf("pop symbols\n");
//   pop_back(test, &prior, &sym);
//   printf("prior = %d, symbol = %c\n", prior, sym);
//   pop_back(test, &prior, &sym);
//   printf("prior = %d, symbol = %c\n", prior, sym);
//   printf("print stack again\n");
//   print_list(test);
//   free_node(test);
//   return 0;
// }

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

void push_back(node *patr, int prior, char b) {
  node *new = NULL;
  create_node(&new, prior, b);
  node *cur = patr;
  while (NULL != cur->next) {
    cur = cur->next;
  }
  cur->next = new;
}

void pop_back(node *patr, int *prior, char *b) {
  node *end = patr;
  node *prev = NULL;
  while (NULL != end->next) {
    prev = end;
    end = end->next;
  }
  *prior = end->prior;
  *b = end->symb;
  prev->next = NULL;
  free(end);
}

void free_node(node *patr) {
  node *curent = patr;
  while (NULL != curent) {
    curent = patr->next;
    free(patr);
    patr = curent;
  }
}

void print_list(node *patr) {
  while (NULL != patr) {
    printf("priority %d ", patr->prior);
    printf("symbol %c\n", patr->symb);
    patr = patr->next;
  }
}

// void add_stack(node **stack, char data, int prior) {
  
// }