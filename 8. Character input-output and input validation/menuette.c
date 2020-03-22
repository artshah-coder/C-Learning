/* menuette.c -- технология меню*/
#include<stdio.h>
#include<ctype.h>

char get_choice (void);
void count (void);
int get_int (void);
char get_first (void);

int main (void)
{
	char ch;
	printf("Введите букву, соответствующую выбранному варианту:\n"
			"a. совет		c. звонок\n"
			"s. подсчет		q. выход\n");
	while ((ch = get_choice()) != 'q')
	{
		switch(ch)
		{
			case 'a':
				printf("Покупайте дешево, продавайте дорого!\n");
				break;
			case 'c':
				printf("\a");
				break;
			case 's':
				count();
				break;
			default:
				printf("Ошибочный ввод!\n");
				break;
		}
		printf("Введите букву, соответствующую выбранному варианту:\n"
				"a. совет               c. звонок\n"
				"s. подсчет             q. выход\n");
	}
	printf("Программа завершена!\n");

	return 0;
}

char get_choice (void)
{
	char ch;
	while ((ch = get_first()) != 'a' && ch != 'c' && ch != 's' && ch != 'q')
		printf("Введите 'a', 'c', 's' или 'q':\n");
	return ch;
}

void count (void)
{
	int i, n;
	printf("Введите натуральное число, до которого вести подсчет: ");
	n = get_int();
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
}

int get_int (void)
{
	int i = 0;

	while (scanf("%d", &i) != 1 || i <= 0)
	{
		(i < 0)?(printf("Ваш ввод: %d", i)):(printf("Ваш ввод "));
		while ((i = getchar()) != '\n')
			putchar(i);
		printf(" не является натуральным числом!\n"
				"Пожалуйста, повторите вновь. Необходимо ввести натуральное число, например, 1, 10, 19, 291: ");
	}
	

	return i;
}

char get_first (void)
{
	char ch;
	while (isspace(ch = getchar()))
		continue;
	while (getchar() != '\n')
		continue;
	return ch;
}
