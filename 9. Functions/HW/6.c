// 6.c -- программа, работающая с адресами переменных
#include<stdio.h>

void change (double *, double *, double *);

int main (void)
{
	double a = 6.67, b = 2.7, c = 3.14;
	printf("Значения вначале: a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);
	change (&a, &b, &c);
	printf("Значения в конце: a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);
	return 0;
}

void change (double * a, double * b, double * c)
{
	double tmp;
	(*a > *b) ? (tmp = *a, *a = *b, *b = tmp) : (*a);
        (*a > *c) ? (tmp = *a, *a = *c, *c = tmp) : (*a);
	(*b > *c) ? (tmp = *b, *b = *c, *c = tmp) : (*a);	
}
