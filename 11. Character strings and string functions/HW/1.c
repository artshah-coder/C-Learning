// 1.c -- упр. 1, стр. 477
#include<stdio.h>
#include<string.h>
#define SIZE 41

void pt_save (char *, char *, int);

int main (void)
{
	char string [SIZE];
	char array [SIZE] = "";
	int ct = -1;
	printf("Введите строку на латинице, не более %d сиволов:\n", SIZE-1);
	fgets(string, SIZE, stdin);
	if ( *(string + strlen (string) - 1) != '\n')
		while (getchar() != '\n')
			continue;
	puts("Вы ввели:");
	printf(string);
	printf("Теперь введите количество символов, от 0, но не более %d, которое вы хотите извлечь из вашей строки в отдельный массив:\n", strlen (string));
	
	while (!scanf("%d", &ct) || (ct < 0 || ct > strlen (string)))
	{
		puts("Ошибка ввода. Повторите:");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
		continue;
	
	pt_save (string, array, ct);
	puts("Отдельный массив:");
	puts(array);
	puts("Программа завершена!");

	return 0;
}

void pt_save (char * st, char * arr, int n)
{
	int i = 0;
	while ( *(st + i) && i < n)
	{
		*(arr + i) = *(st + i);
		i++;
	}
}
