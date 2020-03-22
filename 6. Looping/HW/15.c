// 15.c -- чтение строки ввода и вывод её в обратном порядке
#include<stdio.h>
#include<string.h>
#define STRLEN 255

int main(void)
{
	int i = 0;
	char str[STRLEN];
	printf("Программа читает строку ввода и инвертирует её.\n"
			"Пожалуйста, введите строку:\n");
	do
		scanf("%c", &str[i++]);
	while (str[i-1] != '\n' && i-1 != STRLEN);
	printf("Ваша строка в обратном порядке:\n");
	for (i = strlen(str) - 1 ; i >= 0; i--)
		printf("%c", str[i]);


	return 0;
}
