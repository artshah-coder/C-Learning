/* join_chk.c -- объединяет 2 строки, предварительно проверив размер */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define SIZE 30
#define BUGSIZE 13

char * s_gets (char * st, int n);

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char flower[SIZE];
	char addon[] = " пахнет как старые валенки.";
	char bug[BUGSIZE];
	int available;
	puts ("Какой у вас самый любимый цветок?");
	s_gets(flower, SIZE);
	if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
		strcat (flower, addon);
	puts (flower);
	puts ("Какое у вас любимое насекомое?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen (bug) - 1;
	strncat (bug, addon, available);
	puts (bug);

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
