// 5.c -- программа, генерирующая случайные числа в диапазоне 1..10 и сортирует их по убыванию
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100 // количество генерируемых чисел

void set_nums (int *, int); // функция генерации случайных чисел в заданном количестве
void sort_nums (int *, int); // функция сортировки целочисленного массива заданной размерности
void prnt_array (int *, int); // функция вывода целочисленного массива на экран строчками по 10 элементов

int main (void)
{
	int array [MAX];
	set_nums (array, MAX);
	puts("Неотсортированный массив:");
	prnt_array (array, MAX);
	sort_nums (array, MAX);
	printf("Отсортированный массив:\n");
	prnt_array (array, MAX);
	
	return 0;
}

void set_nums (int * array, int n)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		*(array + i) = rand() % 10 + 1;
}

void sort_nums (int * array, int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (*(array + i) < *(array + j))
			{
				temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = temp;
			}
}

void prnt_array (int * array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(array + i));
		if (!((i+1)%10))
			putchar('\n');
	}
}
