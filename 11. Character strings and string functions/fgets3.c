/* fgets3.c -- использование функции fgets() */
#include<stdio.h>
#define STLEN 10

int main (void)
{
	char words [STLEN];
	int i;
	
	puts ("Input strings (or empty string for exit):");
	while (fgets(words, STLEN, stdin) == words && words[0] != '\n')
	{
		i = 0;
		while (words[i] != '\n' && words[i] != '\0')
			i++;
		if (words[i] == '\n')
			words[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		puts(words);
	}
	puts("That's all!'");
	
	return 0;
}
