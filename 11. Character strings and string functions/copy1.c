/* copy1.c -- ������������ ������������� strcpy() */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define LIM 5
#define SIZE 40

char * s_gets (char *, int);

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char words [LIM] [SIZE];
	char temp [SIZE];
	int i = 0;

	printf("������� %d ���� ������������ � k eng:\n", LIM);
	while (i < LIM && s_gets(temp, SIZE))
		if (temp[0] != 'k')
			printf("������ %s �� ���������� � k eng. ��������� ����:\n", temp);
		else
		{
			strcpy (words[i], temp);
			i++;
		}
	
	printf("������ �������� ����:\n");
	for (i = 0; i < LIM; i++)
		puts(words[i]);

	return 0;
}

char * s_gets (char * st, int n)
{
	if (fgets (st, n, stdin))
		if (st [strlen(st) - 1] == '\n')
			st [strlen(st) - 1] = '\0';
		else
			while (getchar() != '\n')
				continue;

	return st;
}
