// Упр. 7, стр. 156
#include<stdio.h>
#include<float.h>

int main(void)
{
	double n = 1.0/3.0;
	float m = 1.0/3.0;
	printf("double: %.4f %.12f %.16f. DBL_DIG: %d\n", n, n, n, DBL_DIG);
	printf("float: %.4f %.12f %.16f. FLT_DIG: %d\n", m, m, m, FLT_DIG);

	return 0;
}
