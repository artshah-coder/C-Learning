// здесь располагается главная функция
#include"manybooks.h"
#include<stdio.h>

int main (void)
{
	BOOK library [MAXBKS] ;
	int count = 0;
	int index;

	printf("Введите название книги.\n");
	printf("Нажмите Enter в начале строки, чтобы закончить ввод.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0')
	{
		printf("Теперь введите ФИО автора.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Теперь введите цену.\n");
		while (scanf("%f", &library[count].value) != 1)
			printf("Некорректный ввод, повторите.\n");
		eatline();
		count++;
		if (count < MAXBKS)
			printf("Введите название следующей книги.\n");
	}

	if (count > 0)
	{
		printf("Каталог ваших книг:\n");
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
		printf("\nВ алфавитном порядке:\n");
		alphsrt (library, count);
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
		printf("\nВ порядке возрастания цены:\n");
		fltsrt(library, count);
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
	}
	else
		printf("Вообще нет книг? Очень плохо.\n");


	return 0;
}
