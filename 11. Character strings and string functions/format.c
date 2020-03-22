/* format.c -- �������������� ������ */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define MAX 20

char * s_gets (char *, int);

int main (void)
{
	setlocale(LC_ALL, "Rus");
	char first [MAX];
	char last [MAX];
	char formal [2 * MAX + 10];
	double prize;
	
	puts ("������� ���� ���:");
	s_gets (first, MAX);
	puts ("������� ���� �������:");
	s_gets(last, MAX);
	puts("������� ����� ��������� �����:");
	scanf("%lf", &prize);
	sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(formal);

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
