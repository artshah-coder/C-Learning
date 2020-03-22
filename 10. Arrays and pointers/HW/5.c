// 5.c -- Программа-драйвер для функции, возвращающей разность между наибольшим и наименьшим элементами массива
#include<stdio.h>

double shift (double * start, double * end);

int main (void)
{
	double arr[] = { 100.72, 5.67, 84.01, 4000.31, 560,11 };
        printf("Разность между максимальным и минимальным значением массива arr: %.2lf\n", shift (arr, arr + (sizeof arr)/sizeof(double)));
	
	return 0;
}

double shift (double * start, double * end)
{
	double min = *start, max = *start;
	
	while (++start < end)
	{
		*start < min ? (min = *start) : (min);
		*start > max ? (max = *start) : (max);
	}

	return max - min;
}
