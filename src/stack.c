#include "stack.h"

// int main(void) {
//   int prior;
//   char sym;
//   node *test = NULL;
//   push_back(&test, P_M, '+');
//   push_back(&test, P_M, '+');
//   push_back(&test, BR, '(');
//   push_back(&test, BR, '(');
//   push_back(&test, BR, ')');
//   push_back(&test, M_D, '*');
//   push_back(&test, P_M, '-');
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

/*
  @brief Функция создания связного списка возвращающая статус создания
  @param patr сама структура
  @param prior приоритет передаваемого символа
  @param symb передаваемый символ
  @param status статус выполнения
*/
int create_node(node **patr, int prior, char symb) {
  int status = OK;
  /* @param одна ячейка связного списка*/
  node *new = (node *)malloc(sizeof(node)), *ptr;
  new->prior = prior;
  new->symb = symb;
  new->next = NULL;
  if (NULL == new) {
    status = ERR;
  } else {
    if (NULL == (*patr)) {
      (*patr) = new;
    } else {
      ptr = (*patr);
      while(NULL != ptr->next) {
        ptr = ptr->next;
      }
      ptr->next = new;
    }
  }
  return status;
}

void add_stack(node **stack, char b, int prior) {
  // if (NULL == *stack) {
    // create_node(*&stack, prior, b);
  // } else {
    push_back(*&stack, prior, b);
  // }
}

void push_back(node **patr, int prior, char symb) {
  node *new = (node*)malloc(sizeof(node));
  new->prior = prior;
  new->symb = symb;
  if (NULL == (*patr)) {
    new->next = NULL;
    (*patr) = new;
  } else {
    new->next = (*patr);
    (*patr) = new;
  }
}

void pop_back(node **patr, int *prior, char *symb) {
  node *cur;
  cur = (*patr);
  *prior = (*patr)->prior;
  *symb = (*patr)->symb;
  if (NULL != (*patr)) {
    (*patr) = (*patr)->next;
    free(cur);
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