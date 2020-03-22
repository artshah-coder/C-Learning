// 17.c -- программа по расчету счета Чаки Лаки
#include<stdio.h>
#define PERCENT 8
#define SUM 1000000
#define WITHDRAW 100000

int main (void)
{
	double sum = SUM;
	int years = 0;

	while (sum > 0)
	{
		sum +=  sum*PERCENT/100 - WITHDRAW;
		years++;
	}

	printf("Денег на счету не останется через %d лет\n", years);

	return 0;
}
