// sum_arr2.c -- сумма элементов массива
#include<stdio.h>
#define SIZE 10

int sump (int * start, int * end);

int main (void)
{
	int arr [SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long answer = sump (arr, arr + SIZE);
	printf("Общая сумма элементов массива arr равна %ld.\n", answer);

	return 0;
}

int sump (int * start, int * end)
{
	int total = 0;
	
	for (; start < end; start++)
		total += *start;
	
	return total;
}
