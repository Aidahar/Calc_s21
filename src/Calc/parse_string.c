#include "parse_string.h"

int main(void) {
  char data[256] = "(sin(22.2*2)*(12) + 1.2)-1/2*(2^2-2)";
  if (check_brackets(data)) {
    char *notation = calloc(sizeof(char), len_data(data) * 2);
    int status = parse_string(data, notation);
    if (status == OK) {
      printf("data = %s\n", data);
      print_notation(notation);
    } else {
      printf("ERROR MOTHERFUCKER!\n");
    }
    free(notation);
  } else {
    printf("ERRORS MOTHERFUCKER");
  }
  return 0;
}

int parse_string(char *data, char *notation) {
  int status = ERR;
  if (data) {
    struct Node *stack = NULL;
    int jdx, idx, pr;
    char b;
    char *p;
    for (p = data, jdx = 0; *p; ++idx, ++p) { 
      if (is_digit(*p) || *p == '.') {
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
        if (!check_brakets(p)){
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
