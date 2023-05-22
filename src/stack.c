#include "stack.h"

int main(void) {
  int prior;
  char sym;
  node *test = NULL;
  create_node(&test, P_M, '+');
  push_back(&test, BR, '(');
  push_back(&test, BR, ')');
  push_back(&test, M_D, '*');
  printf("all stack\n");
  print_list(test);
  printf("pop symbols\n");
  pop_back(&test, &prior, &sym);
  printf("prior = %d, symbol = %c\n", prior, sym);
  pop_back(&test, &prior, &sym);
  printf("prior = %d, symbol = %c\n", prior, sym);
  printf("print stack again\n");
  print_list(test);
  free_node(&test);
  return 0;
}

int create_node(node **patr, int prior, char b) {
  int status = OK;
  node *tmp = NULL;
  tmp = malloc(sizeof(node));
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
  new = malloc(sizeof(node));
  new->prior = prior;
  new->symb = b;
  new->next = NULL;
  if (NULL == *patr) {
    *patr = new;
  } else {
    node *cur = *patr;
    while (NULL != cur->next) {
      cur = cur->next;
    }
    cur->next = new;
  }
}

void pop_back(node **patr, int *prior, char *b) {
  if (NULL != *patr) {
    if ((*patr)->next == NULL) {
      *prior = (*patr)->prior;
      *b = (*patr)->symb;
      free_node(patr);
    } else {
      node *end = *patr;
      while (NULL != end->next->next) {
        end = end->next;
      }
      *prior = end->next->prior;
      *b = end->next->symb;
      node *del = end->next;
      end->next = NULL;
      free(del);
    }
  }
}

void pop_prior(node **patr, int *prior) {
  if (NULL != *patr) {
    node *tmp = *patr;
    if (tmp->next == NULL) {
      *prior = tmp->prior;
    } else {
      while (tmp->next != NULL) {
        tmp = tmp->next;
      }
      *prior = tmp->prior;
    }
    // free(tmp);
  }
}

void free_node(node **patr) {
  while (*patr) {
    node *curent = (*patr)->next;
    free(*patr);
    *patr = curent;
  }
  *patr = NULL;
}

void print_list(node *patr) {
  while (NULL != patr) {
    printf("priority %d ", patr->prior);
    printf("symbol %c\n", patr->symb);
    patr = patr->next;
  }
}

void add_stack(node **stack, char b, int prior) {
  if (NULL == *stack) {
    create_node(*&stack, prior, b);
  } else {
    push_back(*&stack, prior, b);
  }
  // node *new = malloc(sizeof(new));
  // new->prior = prior;
  // new->symb = b;
  // new->next = NULL;
  // if (NULL == *stack) {
  //   *stack = new;
  // } else {
  //   node *cur = *stack;
  //   while (NULL != cur->next) {
  //     cur = cur->next;
  //   }
  //   cur->next = new;
  // }
}

int check_stack(node **stack) {
  int status = ERR;
  if (NULL == *stack) {
    status = OK;
  }
  return status;
}
