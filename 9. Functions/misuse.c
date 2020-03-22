/* misuse.c -- неправильное использование функции*/
#include<stdio.h>

int imax();

int main (void)
{
	printf("Наибольшим значением из %d и %d является %d.\n",
			3, 5, imax(5));
	printf("Наибольшим значением из %d и %d является %d.\n",
			3, 5, imax(678.51, 5.91));

	return 0;
}

int imax (n, m)
	int n, m;
{
	return n>m?n:m;
}
