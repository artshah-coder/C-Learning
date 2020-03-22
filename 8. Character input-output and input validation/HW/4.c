// 4.c -- программа по расчету среднего количества букв в словах из stdin
#include<stdio.h>
#include<ctype.h>

int main (void)
{
	char ch; // переменная, хранщая текущий символ из stdin
	char previous = '\n'; // переменная для хранения предыдущего "буквенного" символа из stdin
	unsigned int alphs = 0; // общее количество "букв" в stdin
	unsigned int words = 0; // общее количество "слов" в stdin
	double avg_alph; // переменная для хранения среднего количества букв в словах

	printf("Программа подсчитывает среднее количество букв в словах из stdin().\n"
			"Пожалуйста, введите данные (для окончания работы программы нажмите ^D):\n");
	while ((ch = getchar()) != EOF)
	{
		if ((isspace(ch) || ispunct(ch)) && !(isspace(previous) || ispunct(previous)))
			words++;
		else if (!(isspace(ch) || ispunct(ch)))
			alphs++;
		previous = ch;

	}
	printf("В вашем вводе %u слов, среднее количество букв в этих словах: %.2lf\n", words, (double)alphs/(double)words);
	return 0;
}
