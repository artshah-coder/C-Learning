// 1.c -- Упр. 1, стр. 526 -- программа global.c из листинга 12.4, без использования внешних переменных
#include<stdio.h>

void critic (int *); /* прототип функции critic. Параметр - указатель на int,
			дабы функция имела возможность считывать значения в автоматическую переменную, объявленную в main */

int main (void)
{
	int units; // автоматическая переменная с областью видимости в переделах болока main
	printf("Сколько фунтов весит маленький бочонок масла?\n");
	scanf("%d", &units);
	while (units != 56)
		critic(&units);
	printf("Вы знали это!\n");

	return 0;
}

void critic (int * a)
{
	printf("Вам не повезло, попробуйте еще раз.\n");
	scanf("%d", a);
}