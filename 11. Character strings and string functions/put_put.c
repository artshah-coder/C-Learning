// put_put.c -- ������� ������, ������������ �������������
#include<stdio.h>
#include<locale.h>

void put1 (const char *);
int put2 (const char *);

int main (void)
{
	setlocale(LC_ALL, "Rus");
	put1("���� �� � ���� ���� ������� �����, ");
	put1("������� � ��� �� ���������,\n");
	printf("���������� %d ��������.\n",
		put2("�� � ������� �� ��������� �� � ������� ������ ��������."));
	
	return 0;
}

void put1 (const char * string)
{
	while (*string)
		putchar(*string++);
}

int put2 (const char * string)
{
	int count = 0;
	
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');
	
	return count;
}
