/* compback.c -- ��������, ������������ �������� strcmp() */
#include<stdio.h>
#include<string.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	printf("strcmp(\"A\", \"A\") ���������� ");
	printf("%d\n", strcmp("A", "A"));
	
	printf("strcmp(\"A\", \"B\") ���������� ");
	printf("%d\n", strcmp("A", "B"));
	
	printf("strcmp(\"B\", \"A\") ���������� ");
	printf("%d\n", strcmp("B", "A"));
	
	printf("strcmp(\"C\", \"A\") ���������� ");
	printf("%d\n", strcmp("C", "A"));
	
	printf("strcmp(\"Z\", \"a\") ���������� ");
	printf("%d\n", strcmp("Z", "a"));
	
	printf("strcmp(\"apples\", \"apple\") ���������� ");
	printf("%d\n", strcmp("apples", "apple"));
	
	return 0;
}
