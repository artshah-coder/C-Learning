/* binary.c -- переводит неотрицательные целые числа
 из десятичной в двоичную форму записи */
#include<stdio.h>

void to_binary (unsigned long int n);

int main (void)
{
	unsigned long number;
	printf("Введите неотрицательное целое число (q - для завершения программы):\n");
	while (scanf("%lu", &number) == 1)
	{
		printf("Двоичный эквивалент: ");
		to_binary(number);
		putchar('\n');
		printf("Введите целое число (q - для завершения программы):\n");
	}
	printf("Программа завершена!\n");
	return 0;
}

void to_binary (unsigned long int n)
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');
	return;
}
