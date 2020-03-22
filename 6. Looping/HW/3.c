// 3.c -- упр. 3, стр. 244 -- вложенные циклы 2
#include<stdio.h>
#define DIM 6

int main(void)
{
	int i, j;

	for (i = DIM - 1; i >= 0; i--)
	{
		for (j = DIM - 1; j >= i; j--)
			printf("%c", 'A' + j);
		printf("\n");
	}

	return 0;
}
