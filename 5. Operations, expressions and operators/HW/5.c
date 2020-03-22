#include<stdio.h>

int main(void)
{
	int n;
	int sum = 0;
	printf("Введите количество n целых чисел, сумму которых от 0 до n вы хотите вычислить:\n");
	scanf("%d", &n);
		
	while(n-- > 0)
	{
		sum += n+1;
	}

	printf("Сумма равна %d\n", sum);	

	return 0;
}
