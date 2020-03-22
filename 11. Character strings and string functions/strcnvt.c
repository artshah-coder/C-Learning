/* strcnvt.c -- использование функции strtol() */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIM 30

char * s_gets (char * st, int n);

int main (void)
{
	char number [LIM];
	char * end;
	long value;

	puts ("Введите число (или пустую строку для выхода из программы):");
	while (s_gets (number, LIM) && number[0])
	{
		value = strtol (number, &end, 10);
		printf("Десятичный ввод, десятичный вывод: %ld, прекращен на %s (%d)\n", value, end, *end);
		value = strtol (number, &end, 16);
		printf("Шестнадцатиричный ввод, шестнадцатиричный вывод: %ld, прекращен на %s (%d)\n", value, end, *end);
		puts("Следующее число:");
	}
	puts("Программа завершена.\n");	

	return 0;
}

char * s_gets (char * st, int n)
{
	if (fgets (st, n, stdin))
		if (st [strlen(st) - 1] == '\n')
			st [strlen(st) - 1] = '\0';
		else
			while (getchar() != '\n')
				continue;

	return st;
}
