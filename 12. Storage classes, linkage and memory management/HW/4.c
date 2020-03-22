// 4.c -- программа-драйвер для функции, возвращающей количество её вызовов
#include<stdio.h>
#define COUNT 10 // количество итераций цикла для тестирования

int count_calls (int *);

int main (void)
{
	int count = 0;
	int j;
	for(int i = 0; i < COUNT; i++)
		j = count_calls(&count);
	printf("Количество вызовов функции count_calls(): %d\n", j);

	return 0;
}

int count_calls (int * count)
{
	return ++*count;
}
