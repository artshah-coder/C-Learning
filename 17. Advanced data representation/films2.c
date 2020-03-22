/* films2.c -- использование связного списка структур */
#include<stdio.h>
#include<stdlib.h>	/* содержит прототип функции malloc() */
#include<string.h>	/* содержит прототип функции strcpy() */
#define TSIZE	45	/* размер массива для хранения названия */

struct film {
	char title [TSIZE];
	int rating;
	struct film * next;	/* указывает на следующую структуру в списке */
};

char * s_gets (char * st, int n);

int main (void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input [TSIZE];

	/* Сбор и сохранение информации */
	puts("Введите название первого фильма:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc (sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Введите ваш рейтинг фильма <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Введите название следующего фильма (или пустую строку для завершения программы):");
		prev = current;
	}

	/* Отображение списка фильмов */
	if (head == NULL)
		printf("Данные не введены!\n");
	else
		printf("Список фильмов:\n");

	current = head;
	
	while (current != NULL)
	{
		printf("Фильм: %s. Рейтинг: %d\n", current->title, current->rating);
		current = current->next;
	}

	/* Освобождение памяти */

	current = head;

	while (head != NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}

	puts("Программа завершена!");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * find;

	if (fgets(st, n, stdin))
		if ((find = strchr(st, '\n')))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	return st;
}
