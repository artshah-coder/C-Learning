//min_sec.c -- переводит секунды в минуты и секунды
#include<stdio.h>
#define SEC_PER_MIN 60

int main(void)
{
	int sec, min, left;
	printf("Введите количество секунд(<=0 - для выхода):\n");
	scanf("%d", &sec);

	while(sec > 0)
	{
		min = sec/SEC_PER_MIN;
		left = sec%SEC_PER_MIN;
		printf("Количество минут: %d; количество секунд: %d\n", min, left);
		printf("Введите новое значение секунд(<=0 - для выхода):\n");
		scanf("%d", &sec);	
	}

	return 0;
}
