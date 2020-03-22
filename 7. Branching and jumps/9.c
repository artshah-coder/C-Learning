#include<stdio.h>

int main (void)
{
	char ch;

	while ((ch = getchar()) != '#')
		if (ch != '\n')
		{
			printf("Шаг 1\n");
			if (ch == 'b')
				break;
			switch (ch)
			{
				case 'c':
					break;
				default:
					printf("Шаг 2\n");
				case 'h':
					printf("Шаг 3\n");
					break;
			}
		}
		else
			;
	printf("Готово\n");

	return 0;
}
