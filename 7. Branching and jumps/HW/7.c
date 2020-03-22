// 7.c -- Упр. 7, стр. 291 -- программа по вычислению начислений за неделю налогов и чистой зарплаты
#include<stdio.h>
#define BASE_ST 10
#define UPPER_KOEFF 1.5
#define UPPER_HOURS 40
#define TAX_RATE1 0.15
#define SUM1 300
#define TAX_RATE2 0.2
#define SUM2 150
#define TAX_RATE3 0.25

int main (void)
{
	unsigned short hours;
	unsigned int salary = 0;
	unsigned int tax = 0;
	
	printf("Программа вычисляет сумму зарплаты за неделю при базовой ставке $%d в час.\nВведите количество часов, отработанных за неделю:\n", BASE_ST);
	scanf("%hd", &hours);
	if (hours <= 40)
		salary = hours*BASE_ST;
	else
		salary = UPPER_KOEFF*(hours - UPPER_HOURS)*BASE_ST + UPPER_HOURS*BASE_ST;
	
	if(salary <= SUM1)
		tax = salary*TAX_RATE1;
	else if (salary - SUM1 <= SUM2)
		tax = (salary - SUM1)*TAX_RATE2 + SUM1*TAX_RATE1;
	else
		tax = SUM1*TAX_RATE1 + SUM2*TAX_RATE2 + (salary - SUM1 - SUM2)*TAX_RATE3;

	printf("Зарплата за неделю: $%u. Налоги: $%u. Сумма на руки: $%u\n", salary, tax, salary-tax);
	return 0;
}
