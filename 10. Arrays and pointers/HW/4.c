// 4.c -- Программа-драйвер для функции, возвращающей индекс максимального значения в массиве
#include<stdio.h>

int indx_max (const double *, const double *);

int main (void)
{
	double arr[] = { 100000000.72, 5.67, 84.01, 4000.31, 560,11 };
	printf("Индекс максимального значения массива arr: %d\n", indx_max (arr, arr + (sizeof arr)/sizeof(double)));

	return 0;
}

int indx_max (const double * start, const double * end)
{
	int indx = 0;
	int max = *start;

	while (end > start)
		(*(--end) > max) ? (max = *end, indx = end - start) : (max, indx);

	return indx;
}
