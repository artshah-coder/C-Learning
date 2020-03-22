// divisors.c -- вложенные операторы if отображают делители числа
#include<stdio.h>
#include<stdbool.h>

int main (void)
{
	unsigned long num;
	unsigned long div;
	bool isPrime;

	printf("Введите натуральное число для анализа; "
			"для завершения введите q.\n");

	while (scanf("%lu", &num) == 1)
	{
		for (div = 2, isPrime = true; div*div <= num; div++)
		{
			if (num % div == 0)
			{
				if (div*div != num)
					printf("%d делится на %d и %d\n", num, div, num/div);
				else
					printf("%d делится на %d\n", num, div);
				isPrime = false;
			}
		}
		if(isPrime)
			printf("Число %d является простым\n", num);
		printf("Введите новое число;");
		printf("Для завершения нажмите q.\n");
	}
	printf("До свидания.\n");

	return 0;
}
