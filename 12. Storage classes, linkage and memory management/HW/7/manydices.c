// manydices.c -- программа, эмулирующая множество бросаний нескольких костей
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"diceroll.h"

int main(void)
{
	int tosses = 0, dices = 0, sides = 0;
	printf("Введите количество бросаний или q для завершения: ");
	while (scanf("%d", &tosses) && tosses > 0)
	{
		printf("Сколько граней и сколько костей? ");
		scanf("%d%d", &sides, &dices);
		printf("Имеем %d бросаний %d костей с %d гранями.\n", tosses, dices, sides);
		for (int i = 0; i < tosses; i++)
		{
			srand((unsigned int) time (NULL) + (unsigned int) i);
			printf("%4d ", roll_n_dice(dices, sides));
		}
		printf("\nВведите количество бросаний или q для завершения: ");
	}
	printf("Программа завершена!\n");

	return 0;
}
