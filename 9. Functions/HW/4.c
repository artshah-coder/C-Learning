// 4.c -- вычисление среднего гармонического двух чисел double
#include<stdio.h>

double harm (double, double);

int main (void)
{
	double a = 5.69, b = 4.11;
	printf("Среднее гармоническое чисел %.2lf и %.2lf равно %.2lf\n", a, b, harm(a, b));

	return 0;
}

double harm (double x, double y)
{
	return 1/((double)1/2*(1/x + 1/y));
}
