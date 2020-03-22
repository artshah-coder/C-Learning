// factor.c -- использует циклы и рекурсию для вычисления факториалов
#include<stdio.h>

unsigned long fact (unsigned int n);
unsigned long rfact (unsigned int n);

int main (void)
{
	unsigned int num;
	printf("Эта программа вычисляет факториалы.\n");
	printf("Введите значение в диапазоне 0-12 (q для завершения):\n");
	while (scanf("%u", &num) == 1)
	{
		if (num > 12)
			printf("Вводимое значение должно быть меньше 13.\n");
		else
		{
			printf("цикл: факториал %u = %lu\n", num, fact(num));
			printf("рекурсия: факториал %u = %lu\n", num, rfact(num));
		}
		printf("Введите значение в диапазоне 0-12 (q для завершения):\n");
	}
	printf("Программа завершена!\n");

	return 0;
}

unsigned long fact (unsigned int n)
{
	unsigned long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;
	return ans;
}

unsigned long rfact (unsigned int n)
{
	unsigned long ans = 1;
	if (n > 1)
		ans = n*rfact(n-1); 
	else
		ans = 1;

	return ans;
}
