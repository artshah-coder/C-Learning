//Упр 6, стр. 241
#include<stdio.h>
#define NUM 8
#define STRINGS 4

int main (void)
{
	int i, j;
	for(i = 0; i < STRINGS; i++)
	{
		for (j = 0; j < NUM; j++)
			printf("$");
		printf("\n");
	}

	return 0;
}
