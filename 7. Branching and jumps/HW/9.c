// 9.c -- Упр. 9, стр. 291 -- Простые числа
#include<stdio.h>

int main (void)
{
	int num;
	int i, j;
	int count;
	printf ("Введите положительное целое число:\n");
	scanf("%d", &num);
	if (num > 0)
		if (num == 1)
			printf("%d не простое и не составное!\n", num);
		else
		{
			printf("Простые числа, меньшие или равные %d: ", num);
			for (i = 2; i <= num; i++)
			{
				for (j = 2, count = 0; j*j <= i; j++)
					if (i%j == 0)
						count++;
				if(!count)
					printf("%d\t", i);
			}
			printf("\n");
		}
	else
		printf("Вы ошиблись при вводе! Число должно быть > 0!\n");
	return 0;
}
