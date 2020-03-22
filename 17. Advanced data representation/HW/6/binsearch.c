/* binsearch.c -- бинарный поиск в отсортированном по возрастанию массиве */
#include<stdio.h>
#define SZ 11	// размер массива

int binsearch (int * arr, int size, int elem);	// прототип функции бинарного поиска в массиве:
						// arr - отсортированный массив целых чисел
						// size - размер массива
						// elem - искомый элемент
						// функция возвращает 1, если поиск успешен
						// 0 - в противном случае

int main (void)
{
	int i;
	int a[SZ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	printf("Программа поиска элемента в отсортированном по возрастанию массиве.\n");
	printf("Введите элемент, который ищете:\n");
	scanf("%d", &i);
	while (getchar() != '\n')
		continue;
	printf("Элемент %d %s в исходном массиве.\n", i, binsearch(a, SZ, i) ? "содержится": "не содержится");
	puts("Программа завершена!");

	return 0;
}

int binsearch (int * arr, int size, int elem)
{
	unsigned int start = 0;
	unsigned int end = size - 1;
	unsigned int index = (start + end) / 2;
	while (end >= start)
	{
		if (arr[index] == elem)
			return 1;
		else if (arr[index] > elem)
			end = index;
		else
			start = index + 1;
		index = (start + end) / 2;
	}
	return 0;
}
