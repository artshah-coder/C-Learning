// 9.c -- программа драйвер для функции инвертирования строк, упр. 9, стр. 478
#include<stdio.h>
#include<string.h>
#define SIZE 513 // Максимальная длина инвертируемой строки

char * str_invert (char * s);
char * s_gets (char * st, int sz);

int main (void)
{
	char s [SIZE];
	printf("Программа инвертирует введенную с клавиатуры строку.\n");
	printf("Введите строку для инвертирования (или Enter в начале строки для завершения программы):\n");
	while (s_gets(s, SIZE) && *s != '\0')
	{
		printf("Вы ввели: %s\n", s);
		printf("Инвертированная строка: %s\n", str_invert(s));
		printf("Введите строку (или Enter в начале строки для завершения программы):\n");
	}
	puts("Программа завершена!");

	return 0;
}

char * s_gets (char * st, int sz)
{
	if (fgets (st, sz, stdin))
		if (*(st + strlen(st) - 1) == '\n')
			*(st + strlen(st) - 1) = '\0';
		else
			while(getchar() != '\n')
				continue;
	return st;
}

char * str_invert (char * s)
{
	char temp;
	int i;
	for (i = 0; i < strlen(s)/2; i++)
	{
		temp = *(s + i);
		*(s + i) = *(s + strlen(s) - 1 - i);
		*(s + strlen(s) - 1 - i) = temp;
	}

	return s;
}
