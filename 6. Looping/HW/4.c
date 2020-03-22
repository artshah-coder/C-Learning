// 4.c -- упр. 4, стр. 244 -- вложенные циклы 3
#include<stdio.h>
#define DIM 6

int main (void)
{
	int i, j;
	char ch = 'A';
	
	for (i = DIM - 1; i >= 0 ; i--)
	{
		for (j = i; j < DIM; j++)
		{
			printf("%c", ch);
			ch++;
		}
		printf("\n");
	}

	return 0;
}
