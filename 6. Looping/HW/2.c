//2.c -- упр. 2, стр. 244 - вложенные циклы 1
#include<stdio.h>
#define DIM 5

int main (void)
{
	int i, j;
	
	for(i = DIM - 1; i >= 0; i--)
	{
		for (j = 0; j < DIM - i; j++)
			printf("$");
		printf("\n");
	}

	return 0;
}
