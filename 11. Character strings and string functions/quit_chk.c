/* quit_chk.c -- ������ ��������� ��������� */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define EXIT "quit"
#define LIM 10
#define SIZE 80

char * s_gets (char *, int);

int main (void)
{
	setlocale (LC_ALL, "Rus");
	int ct = 0;
	char input [LIM][SIZE];
	printf("������� �� ����� %d ����� (��� quit ��� ������):\n", LIM);
	while (ct < LIM && s_gets(input[ct], SIZE) && strcmp (input[ct], EXIT))
		ct++;
	printf("������� %d �����\n", ct);
	
	return 0;
}

char * s_gets (char * st, int n)
{
	if (fgets (st, n, stdin))
		if (st [strlen (st) - 1] == '\n')
			st [strlen (st) - 1] = '\0';
		else
			while (getchar() != '\n')
				continue;
	return st;
}
