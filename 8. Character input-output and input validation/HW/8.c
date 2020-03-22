// 8.c -- Упр. 8, стр. 291 -- программа по вычислению начислений за неделю налогов и чистой зарплаты
#include<stdio.h>
#include<ctype.h>
#define UPPER_KOEFF 1.5
#define UPPER_HOURS 40
#define TAX_RATE1 0.15
#define SUM1 300
#define TAX_RATE2 0.2
#define SUM2 150
#define TAX_RATE3 0.25

char get_option(void);

int main (void)
{
	char tmp; // переменная для очистки буфера от лишних ссимволов
	unsigned short hours;
	int inpt_st = '\n';
	double base_st;
	double salary = 0;
	double tax = 0;
	printf("***********************************************************************\n");
	printf("Введите букву, соответствующее желаемой тарифной ставке или действию:\n"
			"a. $8.75/ч             b. $9.33/ч\n"
			"c. $10.00/ч            d. $11.20/ч\n"
			"q. Выход\n");
	printf("***********************************************************************\n");
	while ((inpt_st = get_option()) != 'q')
	{
		if (inpt_st  >= 'a' && inpt_st <= 'd')
		{
			switch(inpt_st)
			{
				case 'a':
					base_st = 8.75;
					break;
				case 'b':
					base_st = 9.33;
					break;
				case 'c':
					base_st = 10.00;
					break;
				case 'd':
					base_st = 11.20;
					break;

			}
			printf("Введите количество часов, отраотанных за неделю:\n");
			scanf("%hd", &hours);
			while (getchar() != '\n')
				continue;
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
				"a. $8.75/ч             b. $9.33/ч\n"
				"c. $10.00/ч            d. $11.20/ч\n"
				"q. Выход\n");
		printf("***********************************************************************\n");
	}
	printf("Программа завершена!\n");
		
	return 0;
}

char get_option (void)
{
	char ch;
	while (ch = getchar())
		switch (ch)
		{
			case 'a':
				goto exit;
				break;
			case 'b':
				goto exit;
				break;
			case 'c':
				goto exit;
				break;
			case 'd':
				goto exit;
				break;
			case 'q':
				goto exit;
				break;
			default:
				while (getchar() != '\n')
					continue;
				printf("Ошибка ввода. Повторите:\n");
				break;
		}
exit:	while (getchar() != '\n')
		continue;
	return ch;

}
