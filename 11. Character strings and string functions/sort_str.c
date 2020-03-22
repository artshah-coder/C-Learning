/* sort_str.c -- считывает строки и сортирует их */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define SIZE 81
#define LIM 20
#define HALT ""

void strsrt (char * [], int );

char * s_gets (char *, int);

int main (void)
{
	char input [LIM][SIZE];
	int ct = 0;
	char * ptrst [LIM];
	int k;
	
	setlocale(LC_ALL, "Rus");
	printf("Введите до %d строк, и они будут отсортированы.\n", LIM);
	printf("Для остановки ввода нажмите Enter в начале строки.\n");
	
	while (ct < LIM && s_gets(input[ct], SIZE) && strcmp(input[ct], HALT))
	{
		ptrst [ct] = input[ct];
		ct++;
	}
	
	strsrt (ptrst, ct);
	puts("\nОтсортированный список строк:\n");
	for (k = 0; k < ct; k++)
		puts(ptrst[k]);
	
	return 0;
}

void strsrt (char * strings[], int n)
{
	int i, j;
	char * tmp;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strcmp(strings[i], strings[j]) > 0)
			{
				tmp = strings[i];
				strings[i] = strings[j];
				strings[j] = tmp;
			}
}

char * s_gets (char * st, int n)
{
	if (fgets(st, n, stdin))
		if (st [strlen(st) - 1] == '\n')
			st [strlen(st) - 1] = '\0';
		else
			while (getchar() != '\n')
				continue;
				
	return st;
}
