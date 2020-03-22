// 2.c -- Применение 3-х разных функций копирования массивов
#include<stdio.h>
#define SIZE 5

void copy_arr (double [], const double [], int); // функция копирования массива, написанная в терминологии массивов
void copy_ptr (double *, const double *, int); // функция копирования массива, написанная в терминологии указателей
void copy_ptrs (double *, const double *, const double *); // функция, написанная в терминологии указателей, третьим аргументом принимает адрес, следующий за последним элементом исходного массива
void prnt_arr (const double *, const double *); // функция печати массива

int main (void)
{
	double source [SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1 [SIZE];
	double target2 [SIZE];
	double target3 [SIZE];

	copy_arr (target1, source, SIZE);
	copy_ptr (target2, source, SIZE);
	copy_ptrs (target3, source, source + SIZE);
	
	prnt_arr (target1, target1 + SIZE);
	prnt_arr (target2, target2 + SIZE);
	prnt_arr (target3, target3 + SIZE);

	return 0;
}

void copy_arr (double dst[], const double src[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		dst[i] = src[i];
}

void copy_ptr (double * dst, const double * src, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(dst + i) = *(src + i);
}

void copy_ptrs (double * dst, const double * src, const double * end_src)
{
	while (src < end_src)
	{
		*dst = *src;
		dst++;
		src++;
	}
}

void prnt_arr (const double * start, const double * end)
{
	while (start < end)
	{
		printf("%5.2lf	", *start);
		start++;
	}
	printf("\n");
}
