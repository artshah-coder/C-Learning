// addresses.c -- ������ �����
#define MSG "� ���������."
#include<stdio.h>
#include<locale.h>

int main (void)
{
	setlocale(LC_ALL, "Rus");
	char ar[] = MSG;
	const char * pt = MSG;
	printf("����� \"� ���������.\": %p \n", "� ���������.");
	printf("			����� ar: %p\n", ar);
	printf("			����� pt: %p\n", pt);
	printf("			����� MSG: %p\n", MSG);
	printf("			����� \"� ���������.\": %p\n", "� ���������.");
	
	return 0;
}
