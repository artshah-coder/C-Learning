/* copy2.c -- ������������ ������������� strcpy() */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define WORDS "���������"
#define SIZE 40

int main (void)
{
	setlocale(LC_ALL, "Rus");
	char copy[SIZE] = "������ ������, ��� ����� �� ����.";
	char * ps;
	
	puts(WORDS);
	puts(copy);
	ps = strcpy (copy + 7, WORDS);
	puts(copy);
	puts (ps);
	
	return 0;
}
