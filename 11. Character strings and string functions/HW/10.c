// 10.c -- программа-драйвер для функции, удаляющей все пробелы из строки
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 513 // максимальный размер вводимой строки

char * s_gets (char *, int);
char * del_spaces (char *);

int main (void)
{
	char s [SIZE];
	
	printf("Программа удаляет пробелы из строки.\n");
	printf("Введите строку, длиной не более %d символов (или Enter в начале строки для завершения прораммы):\n", SIZE - 1);
	while (s_gets (s, SIZE) && *s)
	{
		printf("Ваша строка без пробелов:\n%s\n", del_spaces(s));
		printf("Введите новую строку, длиной не более %d символов (или Enter в начале строки для завершения прораммы):\n", SIZE - 1);
	}
	puts("Программа завершена!");

	return 0;
}

char * s_gets (char * s, int n)
{
	if (fgets(s, n, stdin))
		if (*(s + strlen(s) - 1) == '\n')
			*(s + strlen(s) - 1) = '\0';
		else
			while (getchar() != '\n')
				continue;

	return s;
}

char * del_spaces (char * s)
{
	char * temp = s;
	int i = 0;
	while (*temp)
	{
		while (isspace(*temp))
			temp++;
		if (*temp)
			while (!isspace(*temp) && *temp)
				*(s + i++) = *temp++;
	} 
	
	*(s + i) = '\0';
	
	return s;
}
