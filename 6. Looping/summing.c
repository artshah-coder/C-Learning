/* summing.c -- суммирует целые числа, вводимые в интерактивном режиме*/
#include<stdio.h>

int main(void)
{
	long num;
	long sum = 0l;

	printf("Введите целое число для последующего суммирования ");
	printf("(или q для завершения программы): ");
	while (scanf("%ld", &num) == 1)
	{
		sum += num;
		printf("Введите следующее число (или q для выхода): ");
	}

	printf("Сумма введенных целых чисел равна %ld.\n", sum);

	return 0;
}
