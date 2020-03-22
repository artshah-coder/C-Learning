/* width.c -- поля разной ширины */
#include<stdio.h>
#define PAGES 90000

int main()
{
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);

	return 0;
}
