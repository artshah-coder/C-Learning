/* films1.c -- использование массива структур */
#include<stdio.h>
#include<string.h>
#define TSIZE	45	/* размер массива для хранения названия */
#define FMAX	5	/* максимальное количество названий фильмов */

struct film {
	char title [TSIZE];
	int rating;
};

char * s_gets (char *, int);

int main (void)
{
	struct film movies[FMAX];
	int i = 0;
	int j;

	puts("Введите название первого фильма:");
	while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0')
	{
		puts("Введите свое значение рейтинга <0-10>:");
		scanf("%d", &movies[i++].rating);
		while (getchar() != '\n')
			continue;
		puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
	}

	if (i == 0)
		printf("Данные не введены!\n");
	else
		printf("Список фильмов:\n");

	for (j = 0; j < i; j++)
		printf("Фильм: %s Рейтинг: %d\n", movies[j].title, movies[j].rating);
	printf("Программа завершена.\n");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * find;
	if (fgets(st, n, stdin))
		if (find = strchr(st, '\n'))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	return st;
}
