// 12.c -- модифицированная программа из листинга 10.7, модульный подход
#include<stdio.h>
#define MONTHS 12
#define YEARS 5

void total_year (int, float (*)[MONTHS]);
float avg_years (int, float (*)[MONTHS]);
void avg_months (int, float (*)[MONTHS]);

int main (void)
{
	float rain [YEARS] [MONTHS] =
        {
	        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
	        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
	        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
	        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
	        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
        };
	total_year (YEARS, rain);
	printf("\nСреднегодовое количество осадков составляет %.1f дюймов.\n\n", avg_years (YEARS, rain));
	avg_months (YEARS, rain);

	return 0;
}

void total_year (int years, float (*year)[MONTHS])
{
	int i;
	float subtot = 0;
	printf("ГОД	КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
	for (i = 0; i < years*MONTHS; i++)
	{
		if (!((i+1) % 12))
		{
			subtot += *(*year + i);
			printf("%5d %15.1f\n", 2010 + i/12, subtot);
			subtot = 0;
		}
		else
			subtot += *(*year + i);
	}
}

float avg_years (int years, float (*year)[MONTHS])
{
	int i;
	float total = 0;
	for ( i = 0; i < years*MONTHS; i++ )
		total += *(*year + i);
	return total / years;
}

void avg_months (int years, float (*year)[MONTHS])
{
	int i, j;
	float subtot = 0;
	printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n");
	printf("Янв   Фев   Мар   Апр   Май   Июн   Июл   Авг   Сен   Окт   Ноя   Дек\n");
	for (j = 0; j < MONTHS; j++, subtot = 0)
	{
		for (i = 0; i < years; i++)
			subtot += *(*(year + i) + j);
		printf("%4.1f  ", subtot/years);
	}
	printf("\n");
}
