/* fgets.c -- использование функции fgets () и fputs () */
#include<stdio.h>
#define STLEN 15

int main (void)
{
	char words [STLEN];
	puts ("Input your string:");
	fgets (words, STLEN, stdin);
	printf ("Your string, twice output:\n");
	puts (words);
	fputs (words, stdout);
	puts ("Input string again:");
	fgets (words, STLEN, stdin);
	printf ("Your string, twice output:\n");
	puts (words);
	fputs (words, stdout);
	puts ("Thats all");
	
	return 0;
}
