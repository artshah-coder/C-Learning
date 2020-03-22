// power.c -- возводит числа в целые степени
#include<stdio.h>

double power(double n, int p);

int main (void)
{
	int pow;
	double num;
	
	printf("Введите число и положительную целую степень, в которую\n"
			"число будет возведено. "
			"Для завершения программы введите q\n");
	while(scanf("%lf%d", &num, &pow) == 2)
	{
		printf("%.3lf в степени %d равно %.5lf\n", num, pow, power(num, pow));
		printf("Введите число и положительную целую степень, в которую\n"
				"число будет возведено. "
				"Для завершения программы введите q\n");
	}

	return 0;
}

double power(double n, int p)
{
	int i;
	double pow = 1;
	for (int i = 1; i <= p; i++)
		pow *= n;
	
	return pow;
}
