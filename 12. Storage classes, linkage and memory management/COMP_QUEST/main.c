// main.c -- программа-драйвер для функции comp_quest() из comp_quest.c
#include<stdio.h>
#include"comp_quest.h"

int main (void)
{
	int qst, ans;
	qst = comp_quest();
	printf("Компьютер загадал число из диапазона 1..%d\nУ вас 3 попытки, чтобы попытаться отгадать его.\n", MAX);
	for (int count = 0; count < 3; count++)
	{
		printf("Попытка %d. Введите ваш ответ:\n", count + 1);
		while(scanf("%d", &ans) == 0)
		{
			printf("Ошибка ввода! Повторите.\n");
			while (getchar() != '\n')
				continue;
		}
		if (ans == qst)
		{
			printf("Вы правы! Великолепно!\n");
			while(getchar() != '\n')
				continue;
			break;
		}
		else
			if (3 - (count + 1))
				printf("Неверно! Ещё %d попытки(-а). Продолжайте:\n", 3 - (count + 1));

	}
	if (ans != qst)
		printf("К сожалению, вы не смогли угадать. Компьютер загадал %d\n", qst);
	puts("Программа завершена!");

	return 0;
}
