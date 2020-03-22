/* 1.c -- возвращает меньшее из двух чисел типа double*/
#include<stdio.h>

double min (double, double);

int main (void)
{
	double a = 2.34, b = 7.88;
	printf("Из двух вещественных чисел a = %.2lf и b = %.2lf меньшим является %.2lf\n", a, b, min (a, b));
	return 0;
}

double min (double x, double y)
{
	return x < y ? x : y;
}
