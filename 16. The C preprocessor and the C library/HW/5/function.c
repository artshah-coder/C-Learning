#include"header.h"

void selection (const int * ar, int size, int sel)
{
	int res [size];
	int count = 0;
	int pos;

	for (int i = 0; i < size; i++)
		*(res + i) = 0;
	
	srand( (unsigned int) time (NULL));
	while (count < sel)
	{
		pos = rand() % size;
		if (res[pos] == 0)
		{
			res[pos] = ar[pos];
			count++;
		}
	}

	for (int i = 0, count = 0; i < size; i++)
		if (res[i] != 0)
		{
			printf("%d ", res[i]);
			if ( (++count) % 5 == 0)
				putchar('\n');
		}
	putchar('\n');
}

void showarray (const int * ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
		if((i + 1) % 5 == 0)
			putchar('\n');
	}
	putchar('\n');
}
