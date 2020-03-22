// 2.c -- вывод симола в заданных диапазонах столбцов
#include<stdio.h>

void chline (char ch, unsigned char i, unsigned char j); // выводит символ ch в столбцах из диапазона i-j

int main (void)
{
	chline('a', 5, 12);
	return 0;
}

void chline (char ch, unsigned char i, unsigned char j)
{
	unsigned char count = 1;
	if (i > j)
		printf("Ошибка! j < i, что невозможно!\n");
	else
	{
		while (count < i)
		{
			putchar(32);
			count++;
		}
		for(;count <= j; count++)
			putchar(ch);
	}
}
