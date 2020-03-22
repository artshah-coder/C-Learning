// 10.c -- Упр. 10, стр. 292 -- налогообложение в США в 1988 году
#include<stdio.h>
#define TAX_RATE1 0.15
#define TAX_RATE2 0.28
#define SUM1 17850
#define SUM2 23900
#define SUM3 29750
#define SUM4 14850

int main (void)
{
	unsigned short i;
	float income;
	printf("Программа вычисляет сумму налога на 1988 год в США.\n"
			"От вас требуется ввести категорию и сумму дохода.\n");
	printf("Категории:\n"
			"1) Одинокий;						2) Глава семейства\n"
			"3) Состоит в браке, совместное ведение хозяйства	"
			"4) Состоит в браке, раздельное ведение хозяйства\n");
	printf("Введите свою категорию цифрой, пробел и сумму дохода за год в виде вещественного числа (q - для выхода):\n");
	while (scanf("%d %f", &i, &income) == 2)
	{
		switch (i)
		{
			case  1: 
			       printf("Сумма налога равна %.2f\n", (income <= SUM1)?(income*TAX_RATE1):(SUM1*TAX_RATE1+(income-SUM1)*TAX_RATE2));
			       break;
			case 2:
			       printf("Сумма налога равна %.2f\n", (income <= SUM2)?(income*TAX_RATE1):(SUM2*TAX_RATE1+(income-SUM2)*TAX_RATE2));
			       break;
			case 3:
				printf("Сумма налога равна %.2f\n", (income <= SUM3)?(income*TAX_RATE1):(SUM3*TAX_RATE1+(income-SUM3)*TAX_RATE2));
				break;
			case 4:
				printf("Сумма налога равна %.2f\n", (income <= SUM4)?(income*TAX_RATE1):(SUM4*TAX_RATE1+(income-SUM4)*TAX_RATE2));
				break;
		}
		printf("Введите свою категорию цифрой, пробел и сумму дохода за год в виде вещественного числа (q - для выхода):\n");
	}

	printf("Программа завершена!\n");

	return 0;
}
