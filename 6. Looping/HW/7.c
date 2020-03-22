// 7.c -- вывод слова в обратном порядке
#include<stdio.h>
#include<string.h>
#define LENGTH 256

int main (void)
{
	char array[LENGTH];
	int i;
	
	printf("Программа читает слово в символьный массив и выводит его в обратном порядке.\n"
			"Пожалуйста, задайте слово:\n");
	scanf("%s", array);
	
	printf("Введенное вами слово: %s.\n"
			"И в обратном порядке: ", array);
	
	for (i = strlen(array) - 1; i >= 0; i--)
		printf("%c", array[i]);
	printf(".\n");

	return 0;
}
