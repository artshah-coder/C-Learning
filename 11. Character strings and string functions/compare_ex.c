/* compare_ex.c -- считывание ответа на вопрос */
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define ANSWER "GRANT"
#define SIZE 40

char * s_gets (char *, int);
void ToUpper (char *);

int main (void)
{
	char try [SIZE];

	puts ("Кто похоронен в могиле Гранта (ответ введите латиницей, регистр - не важен):");
	s_gets (try, SIZE);
	ToUpper (try);
	while (strcmp (try, ANSWER))
	{
		puts ("Ответ не верный! Попытайтесь еще раз.");
		s_gets (try, SIZE);
		ToUpper (try);
	}
	puts("Верно.");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * find;
	if (fgets (st, n, stdin))
		if (find = strchr (st, '\n'))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	return st;
}

void ToUpper (char * st)
{
	while (*st)
	{
		*st = toupper(*st);
		st++;
	}
}
