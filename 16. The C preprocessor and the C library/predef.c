// predef.c -- предопределенные идентификаторы
#include<stdio.h>

void why_me (void);

int main (void)
{
	printf("Файл: %s.\n", __FILE__);
	printf("Дата: %s.\n", __DATE__);
	printf("Время: %s.\n", __TIME__);
	printf("Версия: is %ld.\n", __STDC_VERSION__);
	printf("Это строка %d.\n", __LINE__);
	printf("Это функция %s\n", __func__);
	why_me();

	return 0;
}

void why_me (void)
{
	printf("Это функция %s\n", __func__);
	printf("Это строка %d.\n", __LINE__);
}
