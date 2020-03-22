// 5.c -- программа-драйвер для функции, ищущей символ в строке
#include<stdio.h>
#include<string.h>
#define SZ 513

char * chrsrch (char *, char);

int main (void)
{
	char st [SZ];
	char c;
	printf("Программа ищет символ в строке.\n"
		"Введите строку, длиной не более %d символов (или Enter вначале строки для завершения работы программы):\n", SZ-1);
	while (fgets (st, SZ, stdin) && *st != '\n')
	{
		if (strlen(st) == SZ-1 && st[strlen(st) - 1] != '\n')
			while (getchar() != '\n')
				continue;
		if (*(st + strlen(st) - 1) == '\n')
			*(st + strlen(st) - 1) = '\0';
		puts("Теперь введите символ, который вы хотите найти в вашей строке:");
		c = getchar();
		while (getchar() != '\n')
			continue;
		if(chrsrch (st, c))
			printf("Первое вхождение символа %c в строку \"%s\" обнаружено на позиции %td\n", c, st, chrsrch(st, c) - st + 1);
		else
			printf("Символ %c отсутствует в строке \"%s\"\n", c, st);
		puts("Введите новую строку (или Enter вначале строки для выхода):");
	}
	puts("Программа завершена!");
	return 0;
}

char * chrsrch (char * string, char c)
{
	char * ret_val = NULL;
	while (*string != '\0')
		if (*string++ == c)
		{
			ret_val = --string;
			break;
		}
	return ret_val;
}
