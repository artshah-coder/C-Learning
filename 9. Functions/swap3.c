// swap3.c -- использование указателей для обмена значениями переменных 
#include <stdio.h>

void interchange (int *, int *);

int main (void)
{
	int x = 5, y = 10;
	printf("Первоначально x = %d, y = %d\n", x, y);
	interchange(&x, &y);
	printf("Теперь x = %d, y = %d\n", x, y);
	return 0;
}

void interchange (int * u, int * v)
{
	int tmp = *u;
	*u = *v;
	*v = tmp;
}
