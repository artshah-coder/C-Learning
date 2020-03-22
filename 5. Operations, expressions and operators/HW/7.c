#include<stdio.h>

long double cube (double a);

int main (void)
{
	double a;
	printf("Введите вещественное число:\n");
	scanf("%lf", &a);
	printf("Значение куба %.2lf  равно: %.2Lf\n", a, cube(a));

	return 0;
}

long double cube(double a)
{
	return (long double) a*a*a;
}
