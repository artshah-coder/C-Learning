#include<stdio.h>
#define M_PER_H 60

int main(void)
{
	int minutes;

	printf("Введите время в минутах:\n <= 0 - для завершения программы\n");
	scanf("%d", &minutes);

	while (minutes > 0)
	{
		printf("%d минут(-ы) - это %d час(-ов | -а) и %d минут(-ы | -а)\n", minutes, minutes / M_PER_H, minutes % M_PER_H);
		printf("Введите время в минутах:\n <= 0 - для завершения программы\n");
		scanf("%d", &minutes);
	}
	return 0;
}
