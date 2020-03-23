/* films3.c -- использование связного списка в стиле ADT	*/
/* компилировать вместе с list.c				*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	/* прототип для exit()		*/
#include"list.h"	/* определение List, Item	*/

// прототипы локальных функций
void showmovies(Item item);		// печать на экране элемента
char * s_gets(char * st, int n);	// альтернатива fgets(), заменяющая '\n' в конце строки на '\0'

int main (void)
{
	List movies;
	Item temp;
	
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "Доступная память отсутствует! Программа завершена.\n");
		exit(EXIT_FAILURE);
	}
	/* сбор и сохранение информации */
	puts("Введите название первого фильма:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Введите свое значение рейтинга <0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "Проблема с выделением памяти.\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("Список полон.");
			break;
		}
		puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
	}

	/* Отображение */
	if (ListIsEmpty(&movies))
		printf("Данные не введены.\n");
	else
	{
		printf("Спиок фильмов:\n");
		Traverse(&movies, showmovies);
	}
	printf("Вы ввели %d фильмов.\n", ListItemCount(&movies));

	/* очистка */
	EmptyTheList(&movies);
	printf("Программа завершена.\n");

	return 0;
}

void showmovies(Item item)
{
	printf("Фильм: %s. Рейтинг: %d.\n", item.title, item.rating);
}

char * s_gets(char * st, int n)
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
