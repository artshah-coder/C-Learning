// 7.c -- Копирование двумерных массивов с использованием функции из файла 2.c
#include<stdio.h>
#define ROWS 2
#define COLS 3

void copy_ptrs (double * dst, const double * src, const double * end_src);
void prnt_arr (const double * start, const double * end);

int main (void)
{
	double src[ROWS][COLS] = { {1.3, 56.71, 11.02}, {5.2, 12.03, 8.29} };
	double dst[ROWS][COLS];
	int i;
	
	for (i = 0; i < ROWS; i++)
		copy_ptrs (*(dst + i), *(src + i), *(src + i) + COLS);

	printf("Скопированный массив:\n");
	for (i = 0; i < ROWS; i++)
		prnt_arr (*(dst + i), *(dst + i) + COLS);

	return 0;
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
	                printf("%5.2lf  ", *start);
	                start++;
	        }
	        printf("\n");
}
