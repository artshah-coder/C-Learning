/* recur.c -- иллюстрация рекурсии */
#include<stdio.h>

void up_and_down (int);

int main (void)
{
	up_and_down(1);

	return 0;
}

void up_and_down (int n)
{
	printf("Уровень %d: ячейка n %p\n", n, &n);
	if (n < 4)
		up_and_down(n+1);
	printf("УРОВЕНЬ %d: ячейка n %p\n", n, &n);
}
