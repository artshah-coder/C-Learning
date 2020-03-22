/* manydice.c -- бросание множества костей	*/
/* компилировать вместе с diceroll.c		*/
#include<stdio.h>
#include<stdlib.h> 	/* для библиотечной функции srand() */
#include<time.h>	/* для функции time() */
#include"diceroll.h"	/* для функции roll_n_dice() */
			/* и переменной roll_count */
int main (void)
{
	int dice, roll;
	int sides, status;

	srand ((unsigned int) time (NULL)); /* рандомизация начального числа с привязкой к системному времени компьютера */
       	printf("Введите количество граней кости или 0 для завершения программы.\n");
	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		printf("Сколько костей?\n");
		if ((status = scanf("%d", &dice)) != 1)
		{
			if (status == EOF)
				break;
			else
			{
				printf("Вы должны ввести целое число."
						" Давайте начнем сначала.\n");
				while (getchar() != '\n')
					continue; /* отбросить некорректный ввод */
				printf("Сколько граней? Для прекращения введите 0.\n");
				continue;
			}
		}
		roll = roll_n_dice (dice, sides);
		printf("Вы бросили %d костей с %d гранями каждая. Выпало %d очков.\n", dice, sides, roll);
		printf("Сколько граней? Для прекращения введите 0.\n");
	}
	printf("Функция rollem() была вызвана %d раз(а).\n", roll_count);
	printf("Пусть удача не покидает вас!\n");

	return 0;
}

