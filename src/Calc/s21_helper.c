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
  if (46 == data || (48 <= data && data <= 57) || 120 == data) {
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
  char *tmp = calloc(sizeof(char), 6);
  for (id = 0; id < 5; ++id, ++data) {
    tmp[id] = *data;
  }
  tmp[5] = '\0';
  if ('a' == *tmp) {
    if (strstr(tmp, "asin(") != NULL) {
      push_back(stack, POW, 'S');
      *idx = 4;
    } else if (strstr(tmp, "acos(") != NULL) {
      push_back(stack, POW, 'C');
      *idx = 4;
    } else if (strstr(tmp, "atan(") != NULL) {
      push_back(stack, POW, 'T');
      *idx = 4;
    }
  } else if ('s' == *tmp || 'c' == *tmp || 't' == *tmp || 'l' == *tmp) {
    if (strstr(tmp, "sin(") != NULL) {
      push_back(stack, POW, 's');
      *idx = 3;
    } else if (strstr(tmp, "cos(") != NULL) {
      push_back(stack, POW, 'c');
      *idx = 3;
    } else if (strstr(tmp, "tan(") != NULL) {
      push_back(stack, POW, 't');
      *idx = 3;
    } else if (strstr(tmp, "sqrt(") != NULL) {
      push_back(stack, POW, 'q');
      *idx = 4;
    } else if (strstr(tmp, "ln(") != NULL) {
      push_back(stack, POW, 'l');
      *idx = 2;
    } else if (strstr(tmp, "log(") != NULL) {
      push_back(stack, POW, 'L');
      *idx = 3;
    } else {
      status = ERR;
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

/*
  @breef функция добавляет в стека скобку
  @params stack_br стек
  @params br скобка
  @params top позиция в стеке
*/
void push_br(char *stack_br, char br, int *top) {
  ++*top;
  stack_br[*top] = br;
}

/*
  @breef функция проверки приоритета
  @params stack_br стек
  @params br скобка
  @params top позиция в стеке
*/
void peek(const char *stack_br, char *br, int top) { *br = stack_br[top]; }

/*
  @breef функция достает из стека скобку
  @params stack_br стек
  @params top позиция в стеке
*/
void pop_br(char *stack_br, int *top) {
  stack_br[*top] = '\0';
  --(*top);
}

/*
  @breef функция проверки числа
  @params data строка данных
  @params notation строка нотации
  @params jdx индексная переменная
  @params idx индексная переменная
*/
int check_numbers(const char *data, char *notation, int *jdx, int *idx) {
  int status = OK, cnt = 0;
  char sym = *data;
  if ('.' == sym) {
    status = ERR;
  } else {
    while (is_digit(sym) || '.' == sym) {
      if (('.' == sym) && (2 > cnt)) {
        ++cnt;
      }
      if (1 < cnt) {
        status = ERR;
        break;
      }
      notation[*jdx] = sym;
      ++(*jdx);
      ++data;
      sym = *data;
      ++(*idx);
    }
  }
  return status;
}

/*
  @breef функция добавления символа в нотацию
  @params notation строка нотации
  @params jdx индексная переменная
  @params sym символ который добавляем
*/
void add_notation(char *notation, int *jdx, char sym) {
  notation[(*jdx)] = sym;
  notation[++(*jdx)] = ' ';
  ++(*jdx);
}

/*
  @breef функция добавления чисел в нотацию
    @params p строка данных
    @params notation строка нотации
  @params jdx индексная переменная
  @params idx индексная переменная
*/
int numbers(char *p, char *notation, int *jdx, int *idx) {
  int status = ERR;
  if (check_numbers(p, notation, &(*jdx), &(*idx))) {
    notation[(*jdx)] = ' ';
    ++(*jdx);
    status = OK;
  }
  return status;
}

/*
  @breef функция проверки скобок
  @params p строка данных
*/
int check_brakets(char *p) {
  int status = OK, id;
  if (2 < len_data(p)) {
    char *tmp = calloc(sizeof(char), 3);
    for (id = 0; id < 2; ++id, ++p) {
      tmp[id] = *p;
    }
    tmp[2] = '\0';
    if (strstr(tmp, ")(") != NULL) {
      status = ERR;
    }
    free(tmp);
  }
  return status;
}

/*
  @breef функция очищающая стек
  @params stack стек операторов
  @params notation строка нотации
  @jdx индексная переменная
  @pr приоритет
  @b  символ
*/
void add_stack_last(node **stack, char *notation, int *jdx, int *pr, char *b) {
  while (!check_stack((*stack))) {
    pop_back(&(*stack), &(*pr), &(*b));
    add_notation(notation, &(*jdx), *b);
  }
}

/*
  @breef функция проверяет первый символ строки
  @params data строка данных
*/
int check_first(const char *data) {
  int status = ERR;
  if ('s' == *data || 'c' == *data || 'a' == *data || 't' == *data ||
      'l' == *data || is_digit(*data) || '+' == *data || '-' == *data) {
    status = OK;
  }
  return status;
}
/*
  @breef функция проверяет корректность ввода операторов
  @params data строка данных
*/
int check_correct_oper(const char *data) {
  int status = OK;
  const char *p = data;
  int len = len_data(p);
  if (2 < len) {
    ++(p);
    if (!is_digit(*p) && !check_trig(*p) && '+' != *p && '-' != *p &&
        '(' != *p) {
      status = ERR;
    }
  }
  return status;
}

/*
  @breef функция проверяет корректность допустимых символов
  @params с символ
*/
int check_trig(char c) {
  int status = ERR;
  if ('s' == c || 'c' == c || 'a' == c || 't' == c || 'l' == c) {
    status = OK;
  }
  return status;
}

/*
  @breef функция проверки корректности строки
  @params data строка данных
*/
int check_correct_string(const char *data) {
  int status = OK;
  if (check_first(data) && check_last_sym(data) && check_brackets(data)) {
    const char *p;
    for (p = data; *p; ++p) {
      if ('\0' != *p && ('*' == *p || '/' == *p || '%' == *p || '^' == *p) &&
          status) {
        status = check_correct_oper(p);
      }
    }
  } else {
    status = ERR;
  }
  return status;
}

int check_last_sym(const char *data) {
  int status = OK;
  int len = len_data(data);
  if (!is_digit(data[len - 1]) && ')' != data[len - 1]) {
    status = ERR;
  }
  return status;
}