#include "s21_helper.h"

/*
  @breef вспомогательная функция считающая длину строки
  @params data строка
*/
int len_data(const char *data) {
  const char *p;
  for (p = data; *p; ++p) {
  }
  return p - data;
}

/*
  @breef вспомогательная функция проверки символа на число
  @params data символ
*/
int is_digit(char data) {
  int status = ERR;
  if (48 <= data && data <= 57) {
    status = OK;
  }
  return status;
}
/*
  @breef вспомогательная функция отображения польской нотации
  @params data строка нотации
*/
void print_notation(char *data) {
  while (*data != '\0') {
    printf("%c", *data);
    ++data;
  }
  printf("\n");
}

/*
  @breef функция проверяет строку на тригонометрические функции и добавляетв
  стек их символы
  @params data входная строка
  @params stack стек операторов
  @idx переменная которая запоминает на сколько сдвинуть строку до следующего
  символа
*/
int is_func(char *data, struct Node **stack, int *idx) {
  int status = OK, id;
  char *tmp = calloc(sizeof(char), 5);
  for (id = 0; id < 4; ++id, ++data) {
    tmp[id] = *data;
  }
  tmp[4] = '\0';
  if ('a' == *tmp) {
    if (strstr(tmp, "asin") != NULL) {
      push_back(stack, POW, 'S');
      *idx = 4;
    } else if (strstr(tmp, "acos") != NULL) {
      push_back(stack, POW, 'C');
      *idx = 4;
    } else if (strstr(tmp, "atan") != NULL) {
      push_back(stack, POW, 'T');
      *idx = 4;
    }
  } else if ('s' == *tmp || 'c' == *tmp || 't' == *tmp || 'l' == *tmp) {
    if (strstr(tmp, "sin") != NULL) {
      push_back(stack, POW, 's');
      *idx = 3;
    } else if (strstr(tmp, "cos") != NULL) {
      push_back(stack, POW, 'c');
      *idx = 3;
    } else if (strstr(tmp, "tan") != NULL) {
      push_back(stack, POW, 't');
      *idx = 3;
    } else if (strstr(tmp, "sqrt") != NULL) {
      push_back(stack, POW, 'q');
      *idx = 4;
    } else if (strstr(tmp, "ln") != NULL) {
      push_back(stack, POW, 'l');
      *idx = 2;
    } else if (strstr(tmp, "log") != NULL) {
      push_back(stack, POW, 'L');
      *idx = 3;
    }
    free(tmp);
    tmp = NULL;
  } else {
    status = ERR;
  }
  return status;
}

/*
  @breef функция проверяет парность скобок
  @params data входная строка
*/
int check_brackets(const char *data) {
  int status = OK;
  int len = len_data(data);
  char *stack_br = calloc(sizeof(char), len);
  // потом переписать на проверку памяти
  if (NULL == stack_br) {
    status = ERR;
  } else {
    int top = -1;
    const char *p;
    for (p = data; *p; ++p) {
      if ('(' == *p) {
        push_br(stack_br, *p, &top);
      } else if (')' == *p) {
        if (-1 == top) {
          status = ERR;
          break;
        } else if ('(' != stack_br[top]) {
          status = ERR;
          break;
        } else {
          pop_br(stack_br, &top);
        }
      }
    }
    if (-1 != top) {
      status = ERR;
    }
  }
  free(stack_br);
  return status;
}

void push_br(char *stack_br, char br, int *top) {
  ++*top;
  stack_br[*top] = br;
}
void peek(const char *stack_br, char *br, int top) { *br = stack_br[top]; }

void pop_br(char *stack_br, int *top) {
  stack_br[*top] = '\0';
  --(*top);
}