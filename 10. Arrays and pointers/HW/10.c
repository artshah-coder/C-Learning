/* 10.c -- Программа-драйвер для функции поэлементного сложения массивов */
#include<stdio.h>
#define SIZE 4 // размер массива

void sum_elements (int, int [*], int [*], int [*]);
void prnt_arr (int, int [*]);

int main (void)
{
	int a1[SIZE] = {13, 47, 59, 80};
	int a2[SIZE] = {11, 0, 43, 61};
	int a3[SIZE];
	int i;
	sum_elements (SIZE, a1, a2, a3);
	prnt_arr(SIZE, a1);
	prnt_arr(SIZE, a2);
	prnt_arr(SIZE, a3);

	return 0;
}

void sum_elements (int size, int a1[size], int a2[size], int a3[size])
{
	int i;
	for (i = 0; i < size; i++)
		*(a3 + i) = *(a1 + i) + *(a2 + i);
}

void prnt_arr (int size, int a[size])
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d	", *(a + i));
	putchar('\n');
}
