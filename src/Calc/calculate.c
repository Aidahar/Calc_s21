#include "calculate.h"

int main(void) {
  char data[256] = "sin(1)";
  double_node stack = {0};
  char *notation = calloc(sizeof(char), len_data(data) * 2);
  int status = parse_string(data, notation);
  if (status == OK) {
    printf("data = %s\n", data);
    double ans = calculate(notation);
    printf("answer = %.7f\n", ans);
  } else {
    printf("ERROR MOTHERFUCKER!\n");
  }
  free(notation);

  return 0;
}

double calculate(char *notation) {
  double result = 0.0, sec, first, answer;
  char *p;
  char double_number[MAXN] = {'\0'};
  int i;
  double_node *numbers = {0};
  for (i = 0, p = notation; *p; ++p) {
    if (is_digit(*p)) {
      result = take_number(&p);
      push_back_dnode(&numbers, result);
      i = 0;
      memset(double_number, 0, sizeof(double_number));
    } else if (is_operator(*p)) {
      if ('+' == *p) plus(&numbers);
      if ('-' == *p) minus(&numbers);
      if ('*' == *p) mul(&numbers);
      if ('/' == *p) divis(&numbers);
      if ('^' == *p) power(&numbers);
      if ('%' == *p) float_mod(&numbers);
    } else if (is_trig(*p)) {
      if ('s' == *p) doubl_sin(&numbers);
    }
  }
  pop_back_double(&numbers, &answer);
  return answer;
}

double take_number(char **notation) {
  int i = 0;
  char double_number[MAXN] = {'\0'};
  while (is_digit(**notation)) {
    double_number[i] = **notation;
    ++i;
    ++*notation;
  }
  return atof(double_number);
}

int is_operator(char c) {
  int status = ERR;
  if ('+' == c || '-' == c || '*' == c || '/' == c || '^' == c || '%' == c) {
    status = OK;
  }
  return status;
}

int is_trig(char c) {
  int status = ERR;
  if ('s' == c || 'S' == c || 'c' == c || 'C' == c || 'l' == c || 'L' == c ||
      't' == c || 'T' == c || 'q' == c) {
    status = OK;
  }
  return status;
}

void plus(double_node **numbers) {
  double first, second, answer;
  pop_back_double(&*numbers, &second);
  pop_back_double(&*numbers, &first);
  answer = first + second;
  push_back_dnode(&*numbers, answer);
}

void minus(double_node **numbers) {
  double first, second, answer;
  pop_back_double(&*numbers, &second);
  pop_back_double(&*numbers, &first);
  answer = first - second;
  push_back_dnode(&*numbers, answer);
}

void mul(double_node **numbers) {
  double first, second, answer;
  pop_back_double(&*numbers, &second);
  pop_back_double(&*numbers, &first);
  answer = first * second;
  push_back_dnode(&*numbers, answer);
}

void divis(double_node **numbers) {
  double first, second, answer;
  pop_back_double(&*numbers, &second);
  pop_back_double(&*numbers, &first);
  answer = first / second;
  push_back_dnode(&*numbers, answer);
}

void power(double_node **numbers) {
  double first, second, answer;
  pop_back_double(&*numbers, &second);
  pop_back_double(&*numbers, &first);
  answer = pow(first, second);
  push_back_dnode(&*numbers, answer);
}

void float_mod(double_node **numbers) {
  double first, second, answer;
  pop_back_double(&*numbers, &second);
  pop_back_double(&*numbers, &first);
  answer = fmod(first, second);
  push_back_dnode(&*numbers, answer);
}

void doubl_sin(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = sin(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_asin(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = asin(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_cos(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = cos(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_acos(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = acos(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_tan(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = tan(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_atan(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = atan(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_ln(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = log(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_log(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = log10(first);
  push_back_dnode(&*numbers, answer);
}

void doubl_sqrt(double_node **numbers) {
  double first, answer;
  pop_back_double(&*numbers, &first);
  answer = sqrt(first);
  push_back_dnode(&*numbers, answer);
}