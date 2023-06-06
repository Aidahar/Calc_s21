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
  @brief Функция создания элемента связного списка возвращающая статус создания
  @param patr сама структура
  @param prior приоритет передаваемого символа
  @param symb передаваемый символ
  @param status статус выполнения
*/
int push_back(node **patr, int prior, char symb) {
  int status = OK;
  node *new = (node *)malloc(sizeof(node));
  if (NULL == new) {
    status = ERR;
  } else {
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
  return status;
}

/*
  @brief Функция взятия верхнего элемента связного списка
  @param patr структура
  @param prior приоритет символа
  @param symb символ
*/
void pop_back(node **patr, int *prior, char *symb) {
  if (NULL != (*patr)) {
    node *cur;
    cur = (*patr);
    *prior = cur->prior;
    *symb = cur->symb;
    (*patr) = (*patr)->next;
    free(cur);
  }
}

/*
  @brief Функция проверки приоритета символа
  @param patr структура
  @param prior приоритет символа
*/
void pop_prior(const node *patr, int *prior) {
  if (NULL != patr) {
    *prior = patr->prior;
  }
}

/*
  @brief Вспомогательная функция для просмотра стека
  @param patr структура
*/
void print_list(node *patr) {
  while (NULL != patr) {
    printf("priority %d ", patr->prior);
    printf("symbol %c\n", patr->symb);
    patr = patr->next;
  }
}

/*
  @brief Вспомогательная функция для проверки на существование стека
  @param stack структура
*/
int check_stack(const node *stack) {
  int status = ERR;
  if (NULL == stack) {
    status = OK;
  }
  return status;
}

/*
  @brief Функция для очистки памяти выделенной под стека
  @param patr структура
*/
void free_node(node **patr) {
  while (*patr) {
    node *curent = (*patr)->next;
    free(*patr);
    *patr = curent;
  }
}

/*
  @brief Функция для добавления оператора в стэк
  @param patr структура
  @notation notation строка нотации
  @jdx индекс строки нотации
  @op оператор
*/
void add_stack(node **patr, char *notation, int *jdx, int op) {
  int pr;
  char b;
  if (patr) {
    pop_prior(*patr, &pr);
    while (pr >= op && !check_stack(*patr)) {
      pop_back(&(*patr), &pr, &b);
      add_notation(notation, &(*jdx), b);
      pop_prior(*patr, &pr);
    }
  }
}

void add_oper_stack();