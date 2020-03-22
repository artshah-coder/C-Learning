// scores_in.c -- использование циклов для обработки массивов
#include<stdio.h>
#define SIZE 10
#define PAR 72

int main (void)
{
	int index, result[SIZE];
	int sum;
	float average;

	printf("Введите %d результатов игры в гольф:\n", SIZE);

	for (index = 0; index < SIZE; index++)
		scanf("%d", &result[index]);

	for (index = 0; index < SIZE; index++)
		printf("%5d", result[index]);
	printf("\n");

	for (index = 0; index < SIZE; index++)
		sum += result[index];
	average = (float)sum / SIZE;
	printf("Набранная сумма: %d. Среднее значение: %f\n", sum, average);
	printf("Гандикап равен %.0f.\n", average - PAR);

	return 0;
}
