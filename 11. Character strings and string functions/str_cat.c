#include<stdio.h>
#include<string.h>
#include<locale.h>
#define SIZE 80

char * s_gets (char * st, int n);

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char flower[SIZE];
	char addon[] = " пахнет как старые валенки.";
	
	puts("Какой у вас любимый цветок?");
	if (s_gets(flower, SIZE))
	{
		strcat (flower, addon);
		puts (flower);
		puts (addon);
	}
	else
		puts ("Обнаружен конец файла!");
	puts("Программа завершена!");

	return 0;
}

char * s_gets (char * st, int n)
{
	if (fgets (st, n, stdin))
		if (st[strlen(st) - 1] == '\n')
			st[strlen(st) - 1] = '\0';
		else
			while (getchar() != '\n')
				continue;
	return st;
}
