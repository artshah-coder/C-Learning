#include<stdio.h>

int main(void)
{
	int a, b;
	printf("Эта программа вычисляет результаты деления по модулю.\n");
	printf("Введите целое число, которое будет служить вторым операндом: ");
	scanf("%d", &b);
	printf("Теперь введите целочисленное значение первого операнда (<= 0 для выхода из программы): ");
	scanf("%d", &a);

	while (a > 0)
	{
		printf("Остаток от деления %d на %d равен %d\n", a, b, a%b);
		printf("Введите следующее целочисленное значение первого операнда (<= 0 для выхода из программы): ");
		scanf("%d", &a);
	}

	return 0;
}
