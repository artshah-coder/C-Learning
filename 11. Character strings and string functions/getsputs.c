/* getsputs.c -- использование функций gets () и puts () */
#include<stdio.h>
#include<locale.h>
#define STLEN 5

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char words[STLEN];
	puts ("Введите строку.");
	gets (words);
	printf ("Ваша строка, выведенная дважды:\n");
	printf ("%s\n", words);
	puts (words);
	puts ("Готово!");
	
	return 0;
}
