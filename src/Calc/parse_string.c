#include "parse_string.h"

// int main(void) {
//   char data[256] = "2+((2)*2)";
//   double_node stack = {0};
//   char *notation = calloc(sizeof(char), len_data(data) * 2);
//   int status = parse_string(data, notation);
//   if (status == OK) {
//     printf("data = %s\n", data);
//   } else {
//     printf("ERROR MOTHERFUCKER!\n");
//   }
//   free(notation);
//   return 0;
// }
/*
  @breef функция перевода строки в польскую нотацию
  @params data строка данных
  @params notation строка польской нотации
*/
int parse_string(char *data, char *notation) {
  int status = ERR;
  if (data && check_correct_string(data)) {
    struct Node *stack = NULL;
    int jdx, idx, pr;
    char b, *p;
    for (p = data, jdx = 0; *p; ++idx, ++p) {
      if (is_digit(*p) || *p == '.' || *p == 'x') {
        int k = 0;
        if (!numbers(p, notation, &jdx, &k)) {
          status = ERR;
          break;
        } else {
          for (; 1 < k; --k, ++p) {
          }
        }
      } else if ('(' == *p) {
        push_back(&stack, BR, *p);
        status = OK;
      } else if ('+' == *p || '-' == *p) {
        add_stack(&stack, notation, &jdx, P_M);
        push_back(&stack, P_M, *p);
        status = OK;
      } else if ('*' == *p || '/' == *p || '%' == *p) {
        add_stack(&stack, notation, &jdx, M_D);
        push_back(&stack, M_D, *p);
        status = OK;
      } else if ('^' == *p) {
        add_stack(&stack, notation, &jdx, POW);
        push_back(&stack, POW, *p);
        status = OK;
      } else if ('s' == *p || 'c' == *p || 'a' == *p || 't' == *p ||
                 'l' == *p) {
        if (is_func(p, &stack, &idx)) {
          for (; 1 < idx; --idx, ++p) {
          }
          status = OK;
        } else {
          status = ERR;
          break;
        }
      } else if (')' == *p) {
        if (!check_brakets(p)) {
          status = ERR;
          break;
        }
        pop_back(&stack, &pr, &b);
        if ('(' != b) {
          add_notation(notation, &jdx, b);
          while ('(' != b) {
            pop_back(&stack, &pr, &b);
            if (b != '(') {
              add_notation(notation, &jdx, b);
            }
          }
        }
        status = OK;
      }
      idx = 0;
    }
    if (status == OK) {
      add_stack_last(&stack, notation, &jdx, &pr, &b);
    }
    free_node(&stack);
  }
  return status;
}
