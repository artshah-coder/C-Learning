// Упр. 3, стр. 288 -- исправление ошибок
#include<stdio.h>

int main (void)
{
	int weight, height;
	scanf("%d %d", &weight, &height);
	if (weight < 100 && height > 64)
		if (height >= 72)
			printf("Ваш вес слишком мал для вашего роста.\n");
		else
			printf("Ваш вес мал для вашего роста.\n");
	else if (weight > 300 && height < 48)
		printf("Ваш рост мал для вашего веса.\n");
	else
		printf("У вас идеальный вес.\n");

	return 0;
}
