// 12_ex.c -- программа, вычисляющая количество слов, букв верхнего и нижнего регистров, цифр и знаков препинания
#include<stdio.h>
#include<ctype.h>

int main (void)
{
	int wc = 0, lowerc = 0, upperc = 0, punctc = 0, digitc = 0;
	char prev = '\n', cur;
	printf("Введите поток символов. Для завершения работы программы, сэмулируйте EOF, нажав Ctrl + D в начале строки:\n");
	while ((cur = getchar()) != EOF)
	{
		if (ispunct(cur))
			punctc++;
		if (isdigit(cur))
			digitc++;
		if (islower(cur))
			lowerc++;
		if (isupper(cur))
			upperc++;
		if (!isalpha(prev) && !isspace(cur))
		{
			if (isalpha(cur))
			{
				prev = cur;
				wc++;
			}
		}
		else
			prev = cur;
	}
	printf("Ваш ввод содержит %d слов, %d заглавных букв, %d строчных букв, %d знаков препинания, %d цифр.\n", wc, upperc, lowerc, punctc, digitc);

	return 0;
}
