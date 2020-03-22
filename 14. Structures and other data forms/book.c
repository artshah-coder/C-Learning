/* book.c -- каталог для одной книги */
#include<stdio.h>
#include<string.h>
char * s_gets(char *, int);
#define MAXTITL 41 /* максимальная длина названия + 1 */
#define MAXAUTL 31 /* максимальная длина имени автора + 1 */

struct book {	/* шаблон структуры: дескриптором является book */
	char title [MAXTITL];
	char author [MAXAUTL];
	float value;
};		/* конец шаблона структуры */

int main (void)
{
	struct book library;	/* объявление library в качестве переменной типа book */

	printf("Введите название книги.\n");
	s_gets(library.title, MAXTITL);	/* доступ к разделу названия книги */
	printf("Теперь введите ФИО автора.\n");
	s_gets(library.author, MAXAUTL);
	printf("Теперь введите цену.\n");
	scanf("%f", &library.value);
	printf("%s авторства %s: $%.2f\n", library.title,
			library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author,
			library.title, library.value);
	printf("Готово.\n");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
		if((find = strchr(st, '\n')))	// поиск символа новой строки
			*find = '\0';		// если найден, меняем на символ конца строки
		else
			while (getchar() != '\n')	// в противном случае, считываем из буфера символы, вплоть до символа новой строки
				continue;
	return ret_val;
}


