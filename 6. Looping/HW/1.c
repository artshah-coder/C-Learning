/*1.c -- упр. 1, стр. 243 -- программа инициализирует и выводит на экран массив из 26 элементов*/
#include<stdio.h>

int main (void)
{
	char alph[26];
	char count;

	for (count = 0; count < (sizeof alph)/sizeof(char); count++)
	{
		alph[count] = 'a' + count;
		printf("%3c ", alph[count]);
	}

	return 0;
}
