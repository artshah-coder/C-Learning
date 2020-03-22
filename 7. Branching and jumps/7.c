/* 7.c -- исправление ошибок в программе */
#include<stdio.h>
#include<ctype.h>

int main (void)
{
	char ch;
	int lc = 0;
	int uc = 0;
	int oc = 0;

	printf("Программа считает строчные, прописные буквы, а также другие символы в строке.\n"
			"Пожалуйста, введите строку (# для окончания ввода):");
	while ((ch = getchar()) != '#')
		if (islower(ch))
			lc++;
		else if (isupper(ch))
			uc++;
		else
			oc++;
	printf("%d строчных, %d прописных, %d других", lc, uc, oc);

	return 0;
}
