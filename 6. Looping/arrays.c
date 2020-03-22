// arrays.c -- границы массива
#include<stdio.h>

int main(void)
{
	int n[10], i;
	for (i = 0; i < (sizeof n)/sizeof(int); i++)
		n[i] = 10;
	printf("%d", n[10]);

	return 0;
}
