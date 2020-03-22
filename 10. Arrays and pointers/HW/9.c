// 9.c -- программа, копирующая и отображающая двумерный массив переменной длины
#include<stdio.h>
#define ROWS 3
#define COLS 5

void cp_arr (unsigned int, unsigned int, double [*][*], double [*][*]);
void prnt_arr (unsigned int, unsigned int, double [*][*]);

int main (void)
{
	double src [ROWS][COLS] = {
		{1.39, 1.02, 0.81, 0.04, 99.21}, {1.06, 72.06, 82.50, 81.53, 1.01}, {0.98, 6.67, 9.11, 4.81, 0.81}
	};

	double dst [ROWS][COLS];
	cp_arr (ROWS, COLS, dst, src);
	printf("Скопированный массив:\n");
	prnt_arr(ROWS, COLS, dst);

	return 0;
}

void cp_arr (unsigned int rows, unsigned int cols, double dst [][cols], double src [][cols])
{
	int i = 0;
	double * ptr;
	for (ptr = *src; ptr < *src + rows*cols; ptr++, i++)
		*(*dst + i) = *ptr;
}

void prnt_arr (unsigned int rows, unsigned int cols, double arr [][cols])
{
	int i;
	for (i = 0; i < rows*cols; i++)
	{
		printf("%5.2lf	", *(*arr + i));
		if (!((i+1)% cols))
			putchar('\n');
	}
}
