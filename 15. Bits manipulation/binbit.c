/* binbit.c -- использование операций с битами для отображения двоичного представления чисел */
#include<stdio.h>
#include<limits.h>
char * itobs (int, char *);
void show_bstr (const char *);

int main (void)
{
	char bin_str[CHAR_BIT*sizeof(int) + 1];
	int number;

	puts("Вводите целые числа и просматривайте их двоичные представления.");
	puts("Нечисловой ввод завершает программу.");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d представляется как ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Программа завершена.");

	return 0;
}

char * itobs (int n, char * str)
{
	static const int size = CHAR_BIT*sizeof(int);
	for (int i = size - 1; i >= 0; i--, n >>= 1)
		str[i] = (0x1 & n) + '0';
	str[size] = '\0';
	return str;
}

void show_bstr (const char * str)
{
	int i = 0;
	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0)
			putchar(' ');
	}
}
