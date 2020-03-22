/* 3.c -- Упр. 3, стр. 291 - считывание и анализ введенных целых чисел*/
#include<stdio.h>

int main (void)
{
	int num;
	unsigned int odd_ct = 0; 
	unsigned int even_ct = 0;
	int odd_sum = 0;
	int even_sum = 0;
	printf ("Программа считает количество четных/нечетных чисел, введенных пользователем.\n"
			"А также считает сумму четных/нечетных чисел.\n"
			"Введите целое число (0 - окончание ввода):\n");
	while (scanf("%d", &num) == 1)
	{
		if (num == 0)
			break;
		if (num % 2 == 0)
		{
			even_ct++;
			even_sum += num;
		}
		else
		{
			odd_ct++;
			odd_sum += num;
		}
		printf("Введите следующее целое число (0 - окончание ввода):\n");
	}

	if (even_ct || odd_ct)
		printf("Ваш ввод содержит %u четных чисел, сумма которых = %d\nи %u нечетных, сумма которых = %d\n", even_ct, even_sum, odd_ct, odd_sum);
	else
		printf("Вы не ввели числа! До свидания!\n");
}
