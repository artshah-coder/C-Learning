// sum_arr1.c -- сумма элементов массива
#include<stdio.h>
#define SIZE 10

int sum (int arr[], int n);

int main (void)
{
	int marbles [SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long answer;
	answer = sum (marbles, SIZE);
	printf("Общая сумма элементов массива marbles равна %d.\n", answer);
	printf("Объём памяти, отведенный под массив marbles, составляет %zd байтов.\n", sizeof marbles);

	return 0;
}

int sum (int arr[], int n)
{
	int i;
	int total = 0;
	for (i = 0; i < n; i++)
		total += *(arr+i);
	printf("Объём памяти, занимаемый ar составляет %zd байтов.\n", sizeof arr);

	return total;
}
