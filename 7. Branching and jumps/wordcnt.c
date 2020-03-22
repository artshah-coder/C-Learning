// wordcnt.c -- производит подсчет символов, слов, строк
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define STP '|'

int main (void)
{
	char ch;
	char prev = '\n';
	bool inword = false;
	int n_words = 0;
	int n_chars = 0;
	int n_lines = 0;
	int p_lines = 0;

	printf("Введите текст для анализа (| для завершения):\n");
	while ((ch = getchar()) != STP)
	{
		n_chars++;
		if (ch == '\n')
			n_lines++;
		if (!inword && !isspace(ch))
		{
			n_words++;
			inword = true;
		}
		if(inword && isspace(ch))
			inword = false;
		prev = ch;
	}
	if(prev != '\n')
		p_lines++;
	printf("Итого введено:\n"
			"-символов: %d\n-слов: %d\n-строк: %d\n-неполных строк: %d\n", n_chars, n_words, n_lines, p_lines);

	return 0;
}
