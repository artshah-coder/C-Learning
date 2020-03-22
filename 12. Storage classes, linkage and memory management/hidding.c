// hidding.c -- переменные в блоках
#include<stdio.h>

int main (void)
{
	int x = 30;
	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);
	{
		int x = 77;
		printf("x во внутреннем блоке: %d по адресу %p\n", x, &x);
	}
	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);
	while (x++ < 33)
	{
		int x = 100;
		x++;
		printf("x в цикле while: %d по адресу %p\n", x, &x);
	}
	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);

	return 0;
}
