/* copy2.c -- демонстрация использования strcpy() */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define WORDS "наихудшим"
#define SIZE 40

int main (void)
{
	setlocale(LC_ALL, "Rus");
	char copy[SIZE] = "Будьте лучшим, чем могли бы быть.";
	char * ps;
	
	puts(WORDS);
	puts(copy);
	ps = strcpy (copy + 7, WORDS);
	puts(copy);
	puts (ps);
	
	return 0;
}
