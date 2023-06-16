#ifndef SRC_CREDIT_CALC_H_
#define SRC_CREDIT_CALC_H_

#include "s21_helper.h"

double calculate_annuitet(double tel_cred, double proc_cred, int month_cred);
double annuitet_percent(double tel_cred, double proc_cred, int month_cred);
double annuitet_dolg_proc(double tel_cred, double proc_cred, int month_cred);
double dif_month_min(double tel_cred, double proc_cred, int month_cred);
double dif_month_max(double tel_cred, double proc_cred, int month_cred);
#endif