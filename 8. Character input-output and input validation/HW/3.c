// 3.c -- программа, подсчитывающая количество прописных, строчных букв и остальных символов в stdin
#include<stdio.h>
#include<ctype.h>

int main (void)
{
	char ch;
	unsigned int count_lower = 0, count_upper = 0, count_other = 0;
	printf("Программа подсчитывает количство строчных, прописных букв, а также количество остальных символов в стандартном вводе.\n"
			"Введите символы. Для окончания - нажмите ^D.\n");
	while ((ch = getchar()) != EOF)
		if (islower(ch))
			count_lower++;
		else if (isupper(ch))
			count_upper++;
		else
			count_other++;
	printf("\nВаш ввод содержит %d прописных, %d строчных, %d остальных символов.\n", count_upper, count_lower, count_other);

	return 0;
}
