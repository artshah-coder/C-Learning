/* fgets2.c -- использование функций fgets () и fputs () */
#include<stdio.h>
#define STLEN 10

int main (void)
{
	char words [STLEN];
	puts ("Input strings (or empty string for exit):");
	
	while (fgets (words, STLEN, stdin) != NULL && words[0] != '\n')
		fputs (words, stdout);
	puts ("That's all!");
	
	return 0;
}
