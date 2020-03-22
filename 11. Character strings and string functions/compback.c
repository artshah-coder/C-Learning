/* compback.c -- значения, возвращаемые функцией strcmp() */
#include<stdio.h>
#include<string.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	printf("strcmp(\"A\", \"A\") возвращает ");
	printf("%d\n", strcmp("A", "A"));
	
	printf("strcmp(\"A\", \"B\") возвращает ");
	printf("%d\n", strcmp("A", "B"));
	
	printf("strcmp(\"B\", \"A\") возвращает ");
	printf("%d\n", strcmp("B", "A"));
	
	printf("strcmp(\"C\", \"A\") возвращает ");
	printf("%d\n", strcmp("C", "A"));
	
	printf("strcmp(\"Z\", \"a\") возвращает ");
	printf("%d\n", strcmp("Z", "a"));
	
	printf("strcmp(\"apples\", \"apple\") возвращает ");
	printf("%d\n", strcmp("apples", "apple"));
	
	return 0;
}
