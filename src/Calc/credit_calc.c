#include "credit_calc.h"

int main(void) {
  printf("первый платеж = %f\n", dif_month_min(20000.0, 12.0, 3 * 12));
  printf("последний платеж = %f\n", dif_month_max(20000.0, 12.0, 3 * 12));
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
  ans = floor(ans * 100.0 + 0.5) / 100.0;
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
  ans = floor(ans * 100.0 + 0.5) / 100.0;
  return ans;
}

/*
  @breef Функция расчета минимального платежа для дифференцированных платежей
  @params tel_cred тело кредита
  @params proc_cred процентная ставка
  @params month_cred период на который выдан кредит
*/
double dif_month_min(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  double od = tel_cred / month_cred;
  ans = od + (tel_cred - od) * month_cred / 12;
  return ans;
}
/*
  @breef Функция расчета минимального платежа для дифференцированных платежей
  @params tel_cred тело кредита
  @params proc_cred процентная ставка
  @params month_cred период на который выдан кредит
  https://maintransport.ru/wiki/differenczirovannyij-platyozh-po-kreditu
  https://calcus.ru/kreditnyj-kalkulyator?input={%22currency%22:%22RUB%22,%22credit_sum_max%22:%22%22,%22type%22:%222%22,%22cost%22:%220%22,%22start_sum_type%22:%221%22,%22start_sum%22:%220%22,%22rest_payment%22:%220%22,%22calc_type%22:%221%22,%22credit_sum%22:%2210%20000%22,%22period%22:%2215%22,%22period_type%22:%22Y%22,%22percent%22:%2229%22,%22payment_type%22:%221%22}
*/
double dif_month_max(double tel_cred, double proc_cred, int month_cred) {
  double ans = 0.0;
  double od = tel_cred / month_cred;
  ans = od + (tel_cred - od * month_cred) * month_cred / 12;
  return ans;
}