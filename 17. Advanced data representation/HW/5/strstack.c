/* strstack.c -- программа-драйвер для пакета интерфеса стека */
/* заталкивает символы строки в стек, затем выталкивает их из стека  и отображает на экране */
#include<stdio.h>
#include<string.h>
#include"stack.h"

/* прототип локаьной функции */
char * s_gets (char * st, int n);	// модификация fgets() - вместо '\n' в конце строки '\0'

int main (void)
{
	char s[MAXITEMS];
	Stack st;
	char temp;
	puts("Программа-драйвер для интерфейса стека.");
	printf("Пожалуйста, введите строку длиной до %d символов:\n", MAXITEMS);
	s_gets(s, MAXITEMS);
	printf("Вы ввели:\n%s\n", s);
	InitializeStack(&st);
	for (int i = 0; *(s + i) != '\0'; i++)
		Push(s + i, &st);
	printf("Символы из строки помещены в стек.\n"
			"Теперь программа вытолкнет и отобразит символы по одному:\n");
	while (!StackIsEmpty(&st))
	{
		Pop(&temp, &st);
		putchar(temp);
	}

	EmptyStack(&st);
	printf("\nПрограмма завершена!\n");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val = fgets(st, n, stdin);
	char * find;
	if ((find = strchr(ret_val, '\n')))
		*find = '\0';
	else
		while (getchar() != '\n')
			continue;

	return ret_val;
}
