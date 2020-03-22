// 3.c - Программа-драйвер для функции, возвращающая наибольшее значение в целочисленном массиве
#include<stdio.h>

int max_value (int * start, int * end);

int main (void)
{
	int arr [] = {5, 7, 11, 145, 67, 10, 8, 341};
	printf("Максимальное значение массива arr: %d\n", max_value (arr, arr + (sizeof arr)/sizeof(int)));

	return 0;
}

int max_value (int * start, int * end)
{
	int max = *start;
	
	while (start < end)
	{
		max = (*start > max) ? (*start) : (max);
		start++;
	}
	
	return max;
}
