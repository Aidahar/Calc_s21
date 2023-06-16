#include "credit_calc.h"

int main(void) {
  printf("платеж = %f\n", calculate_annuitet(20000.0, 12.0, 36 * 12));
  printf("переплата = %f\n", annuitet_percent(20000.0, 12.0, 36 * 12));
  printf("долг с процентами = %f\n",
         annuitet_dolg_proc(20000.0, 12.0, 36 * 12));
  return 0;
}

/*
  @breef Функция расчета аннуиентного платежа
  @params tel_cred тело кредита
  @params proc_cred процентная ставка
  @params month_cred период на который выдан кредит
*/
double calculate_annuitet(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  double PS = proc_cred / (100 * 12);
  ans = tel_cred * (PS / (1 - pow((1 + PS), -month_cred)));
  ans = floor(ans * 100.0 + 0.5) / 100.0;
  return ans;
}

/*
  @breef Функция расчета начисленых процентов
  @params tel_cred тело кредита
  @params proc_cred процентная ставка
  @params month_cred период на который выдан кредит
*/
double annuitet_percent(double tel_cred, double proc_cred, int month_cred) {
  double anu, ans;
  anu = calculate_annuitet(tel_cred, proc_cred, month_cred);
  ans = (anu * month_cred) - tel_cred;
  return ans;
}

/*
  @breef Функция расчета долга с процентами
  @params tel_cred тело кредита
  @params proc_cred процентная ставка
  @params month_cred период на который выдан кредит
*/
double annuitet_dolg_proc(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0, anu_perc;
  anu_perc = annuitet_percent(tel_cred, proc_cred, month_cred);
  ans = tel_cred + anu_perc;
  return ans;
}