/* test_fit.c -- ������������� ������� ������������ ����� */
#include<stdio.h>
#include<string.h>
#include<locale.h>

void fit (char *, unsigned int);

int main (void)
{
	setlocale(LC_ALL, "Rus");
	char mesg[] = "��� ������ ���� ����������� �������,"
		" �� �� �����.";
	
	puts (mesg);
	fit (mesg, 35);
	puts (mesg);
	puts ("���������� ��� ��������� �����.");
	puts (mesg+36); 
	
	return 0;
}

void fit (char * string, unsigned int size)
{
	if (strlen (string) > size)
		string[size] = '\0';
}

