// checking.c -- проверка допустимости ввода
#include<stdio.h>
#include<stdbool.h>
#define MAX 10000000

long get_long (void);
bool bad_limits (long begin, long end, long low, long hight);
double sum_squares (long a, long b);

int main (void)
{	
	long const MIN = -10000000;
	long start, end;
	double answer;
	printf("Программа вычисляет сумму квадратов чисел от нижнего\n"
			"до верхнего предела.\n"
			"Нижний и верхний пределы должны быть в диапазоне от %ld до %ld (для завершения работы программы задайте 0 для обоих пределов).\n", MIN, MAX);
	printf("Задайте нижний предел:\n");
	start = get_long();
	printf("Верхний предел:\n");
	end = get_long();
	while (start != 0 || end != 0)
	{
		if (bad_limits(start, end, MIN, MAX))
			printf("Некорректный ввод, пожалуйста, повторите.\n");
		else
			printf("Сумма квадратов целых чисел от %ld до %ld равна %.2lf.\n", start, end, sum_squares(start, end));
		printf("Задайте новые значения пределов (для завершения программы укажите 0 для обоих пределов).\n"
				"Нижний предел:\n");
		start = get_long();
		printf("Верхний предел:\n");
		end = get_long();

	}
	printf("Программа завершена!\n");

	return 0;
}

long get_long(void)
{
	long input;
	char ch;
	while (scanf("%ld", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" не является целым числом.\n");
		printf("Введите целое число:\n");
	}

	return input;
}

bool bad_limits (long begin, long end, long low, long hight)
{
	bool bad_limits = false;
	if (begin > end)
	{
		printf("Ошибка! %ld больше %ld\n", begin, end);
		bad_limits = true;
	}

	if (begin < low || end < low)
	{
		printf("Значения должны быть равны или больше %ld.\n", low);
		bad_limits = true;
	}

	if (begin > hight || end > hight)
	{
		printf("Значения должны быть меньше или равны %ld.\n", hight);
		bad_limits = true;
	}
	
	return bad_limits;
}

double sum_squares (long a, long b)
{
	int i;
	double sum = 0.0;
	for (i = a; i <= b; i++)
		sum += (double)i * (double)i;
	return sum;

}
