// 11.c -- вывод массива в обратном порядке
#include<stdio.h>
#define LENGTH 8

int main (void)
{
	int array[LENGTH], i;
	printf("Введите данные в целочисленный массив длиной %d:\n", LENGTH);
	for (i = 0; i < LENGTH; i++)
		scanf("%d", &array[i]);
	printf("Вы инициализировали следующий массив:\n");
	for(i = 0; i < LENGTH; i++)
		printf("%3d", array[i]);
	printf("\nОн же, но в обратном порядке:\n");
	for(i = LENGTH-1; i >= 0; i--)
		printf("%3d", array[i]);
	printf("\n");

	return 0;
}
