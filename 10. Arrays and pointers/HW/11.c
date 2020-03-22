// 11.c -- Программа-драйвер для функций печати массива и удваивания значений массива
#include<stdio.h>
#define ROWS 3
#define COLS 5

void prnt_arr (int, int (*)[COLS]);
void x2_arr (int, int (*)[COLS]);

int main (void)
{
	int arr[ROWS][COLS] = {
		{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}
	};
	printf("Исходный массив:\n");
	prnt_arr (ROWS, arr);
	x2_arr (ROWS, arr);
	printf("Удвоенный массив:\n");
	prnt_arr (ROWS, arr);

	return 0;
}

void prnt_arr (int rows, int (*a)[COLS])
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			printf("%d	", *(*(a + i) + j));
		putchar('\n');
	}
}

void x2_arr (int rows, int (*a)[COLS])
{
	int i;
	for (i = 0; i < rows*COLS; i++)
		*(*a + i) *= 2; 
}
