// 11.c -- программа-драйвер для функции Fibonacci(), вычисляющей n-й член последовательности
#include<stdio.h>

int Fibonacci (int);
int correct_input (void);

int main (void)
{
	int n;
	printf("Программа выводит n-й член последовательности Фибоначчи, введенный пользователем.");
	printf("\nВведите целое число, не меньшее 1, задающее номер члена последовательности Фибоначчи:\n");
	n = correct_input();
	printf("%d-й член последовательности Фибоначчи равен %d\n", n, Fibonacci(n));
	return 0;
}

int Fibonacci (int n)
{
	int fib = 0; // переменная для хранения n-ного члена последовательности Фибоначчи
	int pr; // переменная, хранящая значение второго предшествующего члена последовательности
	int tmp; // переменная для организации присваивания корректных значений в переменную pr
	int i; // переменная для организации цикла
	for (i = 1; i <= n; i++)
	{
		if (i < 3)
		{
			fib = 1;
			pr = 1;
		}
		else
		{
			tmp = fib;
			fib += pr;
			pr = tmp;
		}
	}

	return fib;
}

int correct_input (void)
{
	int input;
	while ( (scanf("%d", &input)) != 1 || input < 1)
	{
		while(getchar() != '\n')
			continue;
		printf("Ввод некорректен. Введите целое число, большее 1, например, 5: ");
	}
	return input;
}
