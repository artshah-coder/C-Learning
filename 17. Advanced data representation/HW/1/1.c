// Упр. 1, стр. 789 -- использование двусвязного списка
#include<stdio.h>
#include<stdlib.h>	/* содержит прототип функции malloc() 	*/
#include<string.h>	/* содержит прототип функции strcpy() 	*/
#define TSIZE	45	/* размер массива для хранения названия */

struct film {
	char title[TSIZE];
	int rating;
	struct film * previous;	/* указывает на предыдущую структуру в списке	*/
	struct film * next;	/* указывает на следующую структуру в списке	*/
};

char * s_gets (char * st, int n);

int main (void)
{
	struct film * head = NULL;	// указывает на первый элемент в списке (заголовок) 
	struct film * tail = NULL;	// указывает на последний элемент в списке (хвост)
	struct film * current = NULL;	// указывает на текущий элемент в списке
	struct film * prev = NULL;	// указывает на предыдущий элемент в списке
	char input [TSIZE];		// массив для названия фильма, введенного пользователем

	/* Сбор и сохранение информации */
	puts("Введите название первого фильма:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc (sizeof(struct film));
		if (current == NULL)
		{
			fprintf(stderr, "Динамическая память процесса исчерпана!\n");
			exit(EXIT_FAILURE);
		}
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->previous = prev;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Введите свое значение рейтинга <0-10>:");
		scanf("%u", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
		tail = current;
		prev = current;
	}

	/* Отображение списка фильмов */
	if (head == NULL)
		printf("Данные не введены.\n");
	else
	{
		printf("Список фильмов по порядку ввода:\n");
		for (current = head; current != NULL; current = current->next)
			printf("Фильм: %s Рейтинг: %u\n", current->title, current->rating);
		printf("Список фильмов в обратном порядке:\n");
		for (current = tail; current != NULL; current = current->previous)
			printf("Фильм: %s Рейтинг: %u\n", current->title, current->rating);
	}

	/* Освобождение памяти */
	for (current = head; current != NULL; current = head)
	{
		head = head->next;
		free(current);
	}
	puts("Программа завершена!");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');	// поиск новой строки
		if (find)			// если адрес не равен NULL
			*find = '\0';		// поместить туда нулевой символ
		else
			while (getchar() != '\n')
				continue;	// отбросить остаток строки
	}
	return ret_val;
}

