#include<stdio.h>

int main(void)
{
	int days;
	printf("Введите количество дней (<= 0 - прекращение работы программы):\n");
	scanf("%d", &days);
	while (days > 0)
	{
		printf("%d дней составляет %d неделей и %d дней\n", days, days/7, days%7);
		printf("Введите количество дней (<= 0 - прекращение работы программы):\n");
	        scanf("%d", &days);
	}

	return 0;
}
