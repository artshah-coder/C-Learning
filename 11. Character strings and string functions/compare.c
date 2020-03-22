/* compare.c -- эта программа будет работать */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define ANSWER "Grant"
#define SIZE 40

char * s_gets (char *, int n);

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char try[SIZE];
	puts ("Кто похоронен в могиле Гранта?");
	s_gets (try, SIZE);
	while (strcmp (try, ANSWER))
	{
		puts("Неправильно! Попытайтесь еще раз.");
		s_gets (try, SIZE);
	}
	puts("Теперь правильно!");
	
	return 0;
}

char * s_gets (char * string, int n)
{
	if (fgets (string, n, stdin))
		if (string [strlen (string) - 1] == '\n')
			string [strlen (string) - 1] = '\0';
		else
			while (getchar() != '\n')
				continue;
				
	return string;

}
