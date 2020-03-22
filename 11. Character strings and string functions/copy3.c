/* copy3.c -- демонстрация использования strncpy() */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define SIZE 40
#define TARGSIZE 7
#define LIM 5

char * s_gets (char *, int n);

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char words[LIM][TARGSIZE];
	char temp [SIZE];
	int i = 0;
	printf("Введите %d слов, которые начинаются c k eng:\n", LIM);
	while (i < LIM && s_gets(temp, SIZE))
		if (*temp != 'k')
			printf("%s не начинается с k eng. Повторите ввод.\n");
		else
		{
			strncpy (*(words + i), temp, TARGSIZE - 1);
			*(*(words + i) + TARGSIZE - 1) = '\0';
			i++;
		}
		
	puts("Вот список принятых слов:");
	for (i = 0; i < LIM; i++)
		puts(words[i]);
	
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
