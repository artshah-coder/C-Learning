/* echo_eof.c -- повторяет на экране ввод до достижения конца файла */
#include<stdio.h>

int main (void)
{
	int ch;
	
	while ((ch = getchar()) != EOF)
		putchar(ch);

	return 0;
}

