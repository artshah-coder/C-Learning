// 15.c -- программа-драйвер для собственной реализации функции atoi(), конвертирующей строку в число
#include<stdio.h>
#include<ctype.h>
#define SZ 6

int my_atoi(char *);

int main (void)
{
	char string[SZ] = "14a56";
	printf("Строка string: %s.\nmy_atoi(string) = %d.\n", string, my_atoi(string));

	return 0;
}

int my_atoi (char * s)
{
	int number = 0;
	int i = 0;
	while (*(s + i))
	{
		if (!isdigit(*(s + i)))
		{
			number = 0;
			break;
		}
		else
			if (!number)
			{
				number = 1;
				number *= *(s + i) - '0';
			}
			else
				number = number*10 + *(s + i) - '0';
		i++;
	}

	return number;
}


