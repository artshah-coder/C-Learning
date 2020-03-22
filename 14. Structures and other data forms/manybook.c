/* manybook.c -- каталог для нескольких книг */
#include<stdio.h>
#include<string.h>
char * s_gets (char *, int);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100	/* максимальное количество книг */

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main (void)
{
	struct book library[MAXBKS];	/* массив структур типа book */
	int count = 0;
	int index;

	printf("Введите название книги.\n");
	printf("Нажмите Enter в начале строки, чтобы закончить ввод.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Теперь введите ФИО автора.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Теперь введите цену.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;	/* очистить входную строку */
		if (count < MAXBKS)
			printf("Введите название следующей книги.\n");
	}

	if (count > 0)
	{
		printf("Каталог ваших книг:\n");
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
	}
	else
		printf("Вообще нет книг? Очень плохо.\n");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	char * find;
	if ((ret_val = fgets(st, n, stdin)))
		if ((find = strchr(ret_val, '\n')))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	return ret_val;
}
