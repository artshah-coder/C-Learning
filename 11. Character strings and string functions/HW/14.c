// 14.c -- программа возводит вещественное число в целую степень. Аргументы передаются в командной строке при запуске программы
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main (int argc, char ** argv)
{
	long i;
	long base = 0;
	double exp = 0.0;
	double res = 1.0;
	char * end;
	if (argc == 3)
	{
		exp = strtod(*(argv + 1), &end);
		if (*end)
			printf("Использование: '%s число double число int'\n", *argv);
		else
		{
			base = strtol(*(argv + 2), &end, 10);
			if (*end)
				printf("Использование: '%s число double число int'\n", *argv);
			else
			{
				if (base < 0)
					for (i = 0; i < abs(base); i++)
						res /= exp;
				else
					if (base > 0)
						for (i = 0; i < base; i++)
							res *= exp;
				printf("%g в степени %ld равно %g\n", exp, base, res);
			}
		}
				
	}
	else
		printf("Использование: '%s число double число int'\n", *argv);

	return 0;
}
