// 12.c -- программа, подсчитывающая число слов, цифр, прописных и строчных букв, знаков препинания в стандартном вводе. Ввод из stdin пишется в строку s
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SZ 513 // максимальная длина строки

int wc (char *);
char * s_gets (char *, int);

int main (void)
{
	int ct_lower = 0, ct_upper = 0, ct_punct = 0, ct_dig = 0;
	char s [SZ];
	int i = 0;
	printf("Программа сохраняет введенную в stdin строку в массив s и подсчитывает число слов, цифр, знаков препинания, букв верхнего и нижнего регистров"
		       " в этой строке.\n");
	printf("Введите строку, длиной до %d символов (для завершения нажмите Ctrl+C для эмуляции EOF или Enter в начале строки):\n", SZ - 1);
	while (s_gets(s, SZ) && *s)
	{
		printf("Вы ввели: %s\n", s);
		while (*(s + i))
		{
			if (islower(*(s + i)))
				ct_lower++;
			if (isupper(*(s + i)))
				ct_upper++;
			if (ispunct(*(s + i)))
				ct_punct++;
			if (isdigit(*(s + i)))
				ct_dig++;
			i++;
		}
		printf("Ваш ввод содержит %d слов, %d цифр, %d  строчных букв, %d заглавных букв,  %d знаков препинания.\n", wc(s), ct_dig, ct_lower, ct_upper, ct_punct);
		i = 0;
		ct_dig = 0;
		ct_lower = 0;
		ct_upper = 0;
		ct_punct = 0;
		printf("Введите новую строку, длиной до %d символов (для завершения нажмите Enter в начале строки):\n", SZ - 1);
	}
	puts("Программа завершена!");

	return 0;
}

int wc (char * s)
{
	int count = 0;
	char prev = '\n';
	int i = 0;
	while (*(s + i))
	{
		while (isspace(*(s + i)) && *(s + i))
			prev = *(s + i++);
		if (*(s + i) && !(isspace(*(s + i))) && isspace(prev))
		{
			if (isdigit(*(s + i)) || ispunct(*(s + i++)))
			{
				while (*(s + i) && isdigit(*(s + i)) || ispunct(*(s + i)))
					i++;
				if (*(s + i) && !(isspace(*(s + i))))
				{
					count++;
					i++;
					while (*(s + i) && !(isspace(*(s + i))))
						i++;
					if (*(s + i))
						prev = *(s + i++);
				}
				else
					if (isspace(*(s + i)))
						prev = *(s + i++);
			}
			else
			{
				count++;
				i++;
				while (*(s + i) && !(isspace(*(s + i))))
					i++;
				if (*(s + i))
					prev = *(s + i++);
			}

		}
	}

	return count;
}

char * s_gets (char * s, int n)
{
	if (fgets (s, n, stdin))
		if (*(s + strlen (s) - 1) == '\n')
			*(s + strlen (s) - 1) = '\0';
		else
			while (getchar() != '\n')
				continue;
	return s;
}
