// strings1.c
#include<stdio.h>
#include<locale.h>
#define MSG "� - ����������� ���������� ��������� ���������."
#define MAXLENGTH 81

int main (void)
{
	char words [MAXLENGTH] = "� ������� �������, ���������� � �������.";
	const char * pt1 = "���-�� ��������� �� ����.";
	setlocale (LC_ALL, "Rus");
	puts ("��� ��������� �����:");
	puts (MSG);
	puts (words);
	puts (pt1);
	words [14] = '�';
	puts (words);
	
	return 0;
}
