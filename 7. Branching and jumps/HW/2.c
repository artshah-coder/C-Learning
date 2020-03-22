/*2.c -- Упр. 2, стр. 290 -- Программа выводит каждый введенный символ и его код из таблицы ASCII*/
#include<stdio.h>
#include<ctype.h>
#define N 8 // Сколько пар символ-код выводить в одной строке

int main (void)
{
	char ch;
	unsigned int count = 0;

	printf("Программа выводит введенные символы и их коды в ASCII таблице.\n"
			"Введите строку (завершите ввод #):\n");
	while ((ch = getchar()) != '#')
	{
		count++;
		if (isspace(ch))
			if (ch == ' ')
				printf(" 'space' - %4d;", ch);
			else if (ch == '\t')
				printf(" 'tab' - %4d;", ch);
			else
				printf(" '\\n' - %4d;", ch);
		else
			printf("%2c - %4d;", ch, ch);
		if (count % N == 0)
			printf("\n");
	}

	return 0;
}

