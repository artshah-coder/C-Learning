#include"header.h"

void transform (double * src, double * trg, int n, double (* fp) (double))
{
	for (int i = 0; i < n; i++)
		*(trg + i) = fp(*(src + i));
}

void fill_arr (double * src, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(src + i) = 100000.0 / ((double) rand());
	}
}

double inverse (double x)
{
	return 1.0 / x;
}

double square (double x)
{
	return x*x;
}

void prnt_arr (double * arr, int n)
{
	for (int i = 0; i < n; i++)
		if ((i + 1) % 5)
			printf("%.5lf	", *(arr + i));
		else
			printf("%.5lf\n", *(arr + i));
}
