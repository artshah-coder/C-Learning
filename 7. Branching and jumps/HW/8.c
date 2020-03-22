// 8.c -- Упр. 8, стр. 291 -- программа по вычислению начислений за неделю налогов и чистой зарплаты
#include<stdio.h>
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
	int inpt_st = '\n';
	double base_st;
	double salary = 0;
	double tax = 0;
	printf("***********************************************************************\n");
	printf("Введите число, соответствующее желаемой тарифной ставке или действию:\n"
			"1) $8.75/ч             2) $9.33/ч\n"
			"3) $10.00/ч            4) $11.20/ч\n"
			"5) Выход\n");
	printf("***********************************************************************\n");
	while ((inpt_st = getchar()) != '5')
	{
		if (inpt_st  >= '1' && inpt_st <= '4')
		{
			switch(inpt_st)
			{
				case '1':
					base_st = 8.75;
					break;
				case '2':
					base_st = 9.33;
					break;
				case '3':
					base_st = 10.00;
					break;
				case '4':
					base_st = 11.20;
					break;

			}
			printf("Введите количество часов, отраотанных за неделю:\n");
			scanf("%hd", &hours);
			if (hours <= 40)
				salary = hours*base_st;
			else
				salary = UPPER_KOEFF*(hours - UPPER_HOURS)*base_st + UPPER_HOURS*base_st;
	
			if(salary <= SUM1)
				tax = salary*TAX_RATE1;
			else if (salary - SUM1 <= SUM2)
				tax = (salary - SUM1)*TAX_RATE2 + SUM1*TAX_RATE1;
			else
				tax = SUM1*TAX_RATE1 + SUM2*TAX_RATE2 + (salary - SUM1 - SUM2)*TAX_RATE3;

			printf("Зарплата за неделю: $%.2lf. Налоги: $%.2lf. Сумма на руки: $%.2lf\n", salary, tax, salary-tax);
		}
		printf("***********************************************************************\n");
		printf("Введите число, соответствующее желаемой тарифной ставке или действию:\n"
				"1) $8.75/ч             2) $9.33/ч\n"
				"3) $10.00/ч            4) $11.20/ч\n"
				"5) Выход\n");
		printf("***********************************************************************\n");
	}
	printf("Программа завершена!\n");
		
	return 0;
}
