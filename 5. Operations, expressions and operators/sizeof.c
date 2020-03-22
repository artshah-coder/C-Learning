// sizeof.c -- использование операции sizeof
#include<stdio.h>

int main()
{
	int n = 0;
	size_t intsize;
	intsize = sizeof (int);
	printf("n = %d, n состоит из %zd байтов; все значения типа int состоят из %zd байтов.\n", n, sizeof n, intsize);

	return 0;
}
