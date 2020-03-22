/* hotel.c -- функции управления отелем */
#include <stdio.h>
#include "hotel.h"

int menu(void)
{
	int code, status;
	printf("\n%s\n", STARS);
	printf("Введите число, соответствующее выбранному отелю:\n");
	printf("1) Fairfield Arms	2) Hotel Olympic\n"
			"3) Chertworthy Plaza	4) The Stockton\n"
			"5) Выход\n");
	printf("%s\n", STARS);
	
	while ((status = scanf("%d", &code)) != 1 ||
			(code < 1 || code > 5))
	{
		if (status != 1)
			scanf("%*s");
		printf("Введите целое число от 1 до 5.\n");
	}
	
	return code;
}

int getnights (void)
{
	int nights;

	printf("На сколько суток вы бронируете номер? ");
	while (scanf("%d", &nights) != 1)
	{
		scanf("%*s");
		printf("Введите натуральное значение, такое как 2.\n");
	}

	return nights;
}

void showprice (double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for (n = 1; n <= nights; n++, factor *= (1-DISCOUNT))
		total += factor * rate;
	printf("Общая стоимость составляет $%0.2f.\n", total);
}
