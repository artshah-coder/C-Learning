// 5.c -- заменяет значения переменных double большим значением
#include<stdio.h>

void larger_of (double, double);

int main (void)
{
	larger_of(7.99, 8.11);
	return 0;
}

void larger_of (double x, double y)
{
	printf("Начальные значения: x = %.2lf y = %.2lf\n", x, y);
	(x > y) ? (y = x) : (x = y);
	printf("Конечные значения: x = %.2lf y = %.2lf\n", x, y);
}
