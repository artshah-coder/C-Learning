//Упр. 3, стр. 155
#include<stdio.h>

int main(void)
{
	float i;
	printf("Введите вещественное число:\n");
	scanf("%f", &i);
	printf("%.1f %.1e\n", i, i);

	return 0;
}
