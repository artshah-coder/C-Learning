/* put_out.c -- ������������� ������� puts() */
#include<stdio.h>
#include<locale.h>
#define DEF "� - ������, ������������ ���������� #define."

int main (void)
{
	setlocale(LC_ALL, "Rus");
	char str1[80] = "������ ��� ��������������� ���� ���������.";
	const char * str2 = "��������� ��� ��������������� ���� ���������.";
	puts("� - �������� ������� puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2+4);
	
	return 0;
}
