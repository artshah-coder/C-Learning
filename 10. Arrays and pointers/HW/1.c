/* 1.c -- находит суммарные данные по годам, средние значения за год и средние значения за месяц по данным об осадках за несколько лет,
доступ к элементам массива через указатели */
#include<stdio.h>
#define MONTHS 12
#define YEARS 5

int main (void)
{
	const float rain [YEARS] [MONTHS] = 
	{
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};
	int year, month;
	float subtotal, total;
	printf("ГОД	КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtotal = 0; month < MONTHS; month++)
			subtotal += *(*(rain + year) + month);
		printf("%5d %15.1f\n", 2010+year, subtotal);
		total += subtotal;
	}

	printf("\nСреднегодовое количество осадков составляет %.1lf дюймов\n\n", total/YEARS);
	printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
	printf(" Янв  Фев  Мар  Апр  Май  Июн  Июл  Авг  Сент  Окт"
			"  Ноя  Дек\n");
	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtotal = 0; year < YEARS; year++)
			subtotal += *(*(rain + year) + month);
		printf("%4.1f ", subtotal/YEARS);
	}
	printf("\n");

	return 0;
}
