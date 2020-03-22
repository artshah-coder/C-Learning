// arrchar.c -- ������ ����������, ������ �����
#include<stdio.h>
#include<locale.h>
#define SLEN 40
#define LIM 5

int main (void)
{
	setlocale (LC_ALL, "Rus");
	const char * mytalents [LIM] = {
	"���������� ����������� �����",
	"������ ���������", "������������ ������",
	"���������� ���������� � ��������� �� �����",
	"������ ����� ���������������� �"
	};
	
	char yourtalents[LIM][SLEN] = {
	"�������� �� ������",
	"�������� ���", "�������� �����������",
	"�������� �����", "������ ����������� �����"
	};
	
	int i;
	
	puts ("������� ���� �������.");
	printf ("%-52s %-25s\n", "�� �������", "���� �������");
	for (i = 0; i < LIM; i++)
		printf ("%-52s %-25s\n", mytalents[i], yourtalents[i]);
	printf("\n������ mytalents: %zd, ������ yourtalents: %zd\n",
		sizeof (mytalents), sizeof (yourtalents));
	
	return 0;
}
