/* starsrch.c -- ������������� ������� strncmp() */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define LISTSIZE 6

int main (void)
{
	setlocale (LC_ALL, "Rus");
	const char * list[LISTSIZE] = {
		"����������", "��������",
		"�����������", "���������",
		"��������", "����������"
	};
	
	int count = 0;
	int i;
	
	for (i = 0; i < LISTSIZE; i++)
		if (strncmp (list[i], "�����", 5) == 0)
		{
			printf("�������: %s\n", list[i]);
			count++;
		}
	printf("���������� ���� � ������,"
			" ������������ � �����: %d\n", count);

	return 0;
}
