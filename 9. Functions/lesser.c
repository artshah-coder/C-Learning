/* lesser.c -- выбирает меньшее из двух зол */
#include<stdio.h>

int imin (int, int);

int main (void)
{
	int evil1, evil2;
	printf("Введите два целых числа (или q для выхода):\n");
	while (scanf("%d%d", &evil1, &evil2) == 2)
	{
		printf("Меньшим из двух чисел %d %d является %d\n", evil1, evil2, imin (evil1, evil2));
		printf("Введите два целых числа (или q для выхода):\n");
	}
	printf("Программа завершена!\n");

	return 0;
}

int imin (int n, int m)
{
	return n<m?n:m;
}
