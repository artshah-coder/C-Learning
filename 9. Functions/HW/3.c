/* 3.c -- вывод матрицы символов на экран */
#include<stdio.h>

void char_matrix (char, unsigned int, unsigned int);

int main (void)
{
	char_matrix('a', 5, 3);
	return 0;
}

void char_matrix (char ch, unsigned int n, unsigned int m)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			putchar(ch);
		putchar('\n');
	}
}
