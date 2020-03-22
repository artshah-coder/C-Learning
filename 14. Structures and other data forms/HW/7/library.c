// library.c -- файл с определением функций
#include"library.h"

char * s_gets (char * st, int n)
{
	char * ret_val = fgets(st, n, stdin);
	char * find;
	if (ret_val)
		if ((find = strchr(ret_val, '\n')))
			*find = '\0';
		else
			eatline();
	return ret_val;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

void ld (FILE * f, BOOK * library, int n)
{
	int index = 0;
	rewind(f);
	while (index < n && fread(&library[index].main, sizeof(struct book), 1, f) && (strlen(library[index].main.title) > 0 || strlen(library[index].main.author) > 0))
		library[index++].status = 0;
}

int readf (FILE * f)
{
	struct book b;
	int index = 0;
	rewind(f);
	while (fread(&b, sizeof(struct book), 1, f) &&
			(strlen(b.title) > 0 || strlen(b.author) > 0))
	{
		if (index == 0)
			puts("Текущее содержание файла book.dat:");
		printf("%d. %s авторства %s: $%.2f\n", index + 1,
				b.title, b.author, b.value);
		index++;
	}
	return index;
}

void unld (FILE * f, BOOK * library, int n)
{
	int index = 0;
	int count = 0;
	struct book tmp;
	struct book empty = {"\0", "\0", 0.0};
	for (index = 0; index < n; index++)
	{
		if (library[index].status != 1)
		{
			fseek(f, (long) sizeof(struct book)*count++, SEEK_SET);
			fwrite(&library[index].main, sizeof(struct book), 1, f);
		}
	}
	rewind(f);
	index = 0;
	while (fread(&tmp, sizeof(struct book), 1, f))
		index++;
	if (index > count)
		while (count < index)
		{
			fseek(f, (long) sizeof(struct book)*count++, SEEK_SET);
			fwrite(&empty, sizeof (struct book), 1, f);
		}
}

void del_rec (int pos, BOOK * library)
{
	library[pos - 1].status = 1;
	printf("Запись %d помечена как удаленная.\n", pos);
}

void edit_rec (int pos, BOOK * library)
{
	puts("Введите название книги.");
	while (s_gets(library[pos - 1].main.title, MAXTITL) == NULL ||
			library[pos - 1].main.title[0] == '\0')
		fputs("Ошибка. Пожалуйста, введите название книги.\n", stderr);
	puts("Введите имя автора.");
	while (s_gets(library[pos - 1].main.author, MAXAUTL) == NULL ||
			library[pos - 1].main.author[0] == '\0')
		fputs("Ошибка. Пожалуйста, введите имя автора.\n", stderr);
	puts("Введите цену книги.");
	while (scanf("%f", &library[pos - 1].main.value) != 1 ||
			library[pos - 1].main.value < 0)
	{
		fputs("Ошибка. Пожалуйста, введите корректную цену.\n", stderr);
		eatline();
	}
	eatline();
	library[pos - 1].status = 2;
	printf("Запись %d изменена.\n", pos);
}

void add_rec (int pos, BOOK * library)
{
	puts("Введите название новой книги.");
	while (s_gets(library[pos].main.title, MAXTITL) == NULL ||
			library[pos].main.title[0] == '\0')
		fputs("Ошибка. Пожалуйста, введите название книги.\n", stderr);
	puts("Теперь введите имя автора.");
	while (s_gets(library[pos].main.author, MAXAUTL) == NULL ||
			library[pos].main.author[0] == '\0')
		fputs("Ошибка. Пожалуйста, введите имя автора.\n", stderr);
	puts("Теперь введите цену книги.");
	while (scanf("%f", &library[pos].main.value) != 1 ||
			library[pos].main.value < 0)
	{
		fputs("Ошибка. Пожалуйста, введите корректную цену.\n", stderr);
		eatline();
	}
	eatline();
	library[pos].status = 0;
	printf("Запись добавлена в позицию %d.\n", pos + 1);
}
