// 8.c -- копирование части одного массива в другой с применением функции из файла 2.с
#include<stdio.h>
#define SZ1 7
#define SZ2 3

void copy_ptrs (double * dst, const double * src, const double * end_src);
void prnt_arr (const double * start, const double * end);

int main (void)
{
	double arr1[SZ1] = { 4.56, 11.03, 7.04, 8.00, 5.11, 3.21, 9.05 };
	double arr2[SZ2];
	printf("%d-элементный массив:\n", SZ1);
	prnt_arr (arr1, arr1 + SZ1);
	printf("%d-элементный массив после копирования:\n", SZ2);
	copy_ptrs (arr2, arr1 + 2, arr1 + 5);
	prnt_arr (arr2, arr2 + SZ2);

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
