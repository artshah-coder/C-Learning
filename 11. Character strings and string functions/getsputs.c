/* getsputs.c -- ������������� ������� gets () � puts () */
#include<stdio.h>
#include<locale.h>
#define STLEN 5

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char words[STLEN];
	puts ("������� ������.");
	gets (words);
	printf ("���� ������, ���������� ������:\n");
	printf ("%s\n", words);
	puts (words);
	puts ("������!");
	
	return 0;
}
