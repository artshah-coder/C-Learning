#include<stdio.h>

int main(void)
{
	int a;
	printf("Введите целое число:\n");
	scanf("%d", &a);
	while(a <= a + 10)
	{
		printf("%5d ", a);
		a++;
	}
	return 0;
}
