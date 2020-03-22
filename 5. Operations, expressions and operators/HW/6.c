#include<stdio.h>

int main(void)
{
	int n;
	long long sum = 0;
	printf("Введите количество n целых чисел, сумму квадратов которых от 0 до n вы хотите вычислить:\n");
	scanf("%d", &n);
	
	while(n-- > 0)
	{
		sum += (n+1)*(n+1);
	}

	printf("Сумма равна %lld\n", sum);	

	return 0;
}
