// Упр. 4, стр. 155
#include<stdio.h>

int main(void)
{
	char name[15];
	float h;
	printf("Введите ваше имя и рост в см через пробельный символ:\n");
	scanf("%s %f", name, &h);
	printf("%s, ваш рост составляет %.2.2f м\n", name, h/100);

	return 0;
}
