/* summing.c -- суммирует целые числа, вводимые в интерактивном режиме*/
#include<stdio.h>

int main(void)
{
	long num;
	long sum = 0l;
	int status;

	printf("Введите целое число для последующего суммирования ");
	printf("(или q для завершения программы): ");
	status = scanf("%ld", &num);
	while (status = 1)
	{
		sum += num;
		printf("Введите следующее число (или q для выхода): ");
		status = scanf("%ld", &num);
	}

	printf("Сумма введенных целых чисел равна %ld.\n", sum);

	return 0;
}
