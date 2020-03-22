// boolean.c -- использование переменной типа _Bool
#include<stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	_Bool input_is_good;
	printf("Введите целое число для последующего суммирования ");
	printf("(или q для завершения программы): ");
	input_is_good = (1 == scanf("%ld", &num));
	while(input_is_good)
	{
		sum += num;
		printf("Введите следующее целое число (или q для завершения программы): ");
		input_is_good = (1 == scanf("%ld", &num));
	}
	printf("Сумма введенных целых чисел равна %ld.\n", sum);

	return 0;
}
