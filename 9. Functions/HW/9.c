// 9.c - программа, содержащая рекурсивную функцию возведения вещественного числа в целую степень
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

double rpower (double, int);

int main (void)
{
	double a;
	int b;
	printf("Драйвер для функции возведения вещественного числа в целую степень.\n");
	printf("Введите вещественное число и целую степень в которую желаете его возвести: ");
	while (scanf("%lf%d", &a, &b) != 2)
	{
		while (getchar() != '\n')
			continue;
		printf("Повторите попытку! Требуется вещественное число и целая степень, в которую это число надо возвести: ");
	}
	printf("Результат возведения %g в степень %d ревен %g\n", a, b, rpower(a, b));
	printf("Программа окончена!\n");
	return 0;
}

double rpower (double n, int k)
{
	double res = 1.0;
	if ( n < FLT_EPSILON && n > 0)
		if (k == 0)
			printf("Результат возведения %g в степень %d не определен. Используется значение %g.\n", n, k, res = 1.0);
		else
			res = 0.0;
	else
		if (k == 0)
			res = 1.0;
		else if (k > 0)
				res = n*rpower(n, k-1);
		else 
				res = 1/n*rpower(n, k+1);

	return res;
}
