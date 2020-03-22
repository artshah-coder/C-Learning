// 6.c -- Программа-драйвер для функции инвертирования массива
#include<stdio.h>

void invert (double * start, double * end); // функция, инвертирующая массив
void prnt_arr (double *, double *);

int main (void)
{
	double arr[] = {1.56, 79.01, 541.8, 5.11, 8.99};
	printf("Исходный массив:\n");
	prnt_arr (arr, arr + (sizeof arr)/sizeof(double));
	invert(arr, arr + (sizeof arr)/sizeof(double));
	printf("Инвертированный:\n");
	prnt_arr (arr, arr + (sizeof arr)/sizeof(double));

	return 0;
}

void invert (double * start, double * end)
{
	double tmp; // промежуточная переменная для организации обмена значениями между элементами массива
	double * middle = start + (end - start)/2; // указатель на середину массива
	
	while ( start < middle )
	{
		tmp = *start;
		*start = *--end;
	        *end = tmp;
		start++;	
	}
}

void prnt_arr (double * start, double * end)
{
	while (start < end)
	{
		printf("%.2lf	", *start);
		start++;
	}
	putchar('\n');
}
