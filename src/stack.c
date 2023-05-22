#include "stack.h"

// int main(void) {
//   int prior;
//   char sym;
//   node *test = NULL;
//   create_node(&test, P_M, '+');
//   push_back(&test, BR, '(');
//   push_back(&test, BR, ')');
//   push_back(&test, M_D, '*');
//   printf("all stack\n");
//   print_list(test);
//   printf("pop symbols\n");
//   pop_back(&test, &prior, &sym);
//   printf("prior = %d, symbol = %c\n", prior, sym);
//   pop_back(&test, &prior, &sym);
//   printf("prior = %d, symbol = %c\n", prior, sym);
//   printf("print stack again\n");
//   print_list(test);
//   free_node(&test);
//   return 0;
// }

/*  */
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

void add_stack(node **stack, char b, int prior) {
  if (NULL == *stack) {
    create_node(*&stack, prior, b);
  } else {
    push_back(*&stack, prior, b);
  }
}

void push_back(node **patr, int prior, char b) {
  node *new;
  create_node(&new, prior, b);
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

void pop_back(node **patr, int *prior, char *symb) {
  if (NULL != *patr) {
    if (NULL == (*patr)->next) {
      *prior = (*patr)->prior;
      *symb = (*patr)->symb;
      *patr = NULL;
    } else {
      node *last = (*patr);
      while (NULL != last->next->next) {
        last = last->next;
      }
      *prior = last->next->prior;
      *symb = last->next->symb;
      free(last->next);
      last->next = NULL;
    }
  }
}

void pop_prior(const node *patr, int *prior) {
  if (NULL != patr) {
    const node *tmp = patr;
    if (tmp->next == NULL) {
      *prior = tmp->prior;
    } else {
      while (tmp->next != NULL) {
        tmp = tmp->next;
      }
      *prior = tmp->prior;
    }
  }
}

void print_list(node *patr) {
  while (NULL != patr) {
    printf("priority %d ", patr->prior);
    printf("symbol %c\n", patr->symb);
    patr = patr->next;
  }
}

int check_stack(const node *stack) {
  int status = ERR;
  if (NULL == stack) {
    status = OK;
  }
  return status;
}

void free_node(node **patr) {
  while (*patr) {
    node *curent = (*patr)->next;
    free(*patr);
    *patr = curent;
  }
}