/* showchar1.c -- программа с крупной проблемой ввода-вывода */
#include<stdio.h>

void display (char ch, int n, int m);

int main (void)
{
	int ch;
	int a, b;
	printf("Введите символ и 2 натуральных числа:\n");
	while ((ch = getchar()) != '\n')
	{
		if(scanf("%d%d", &a, &b) != 2)
			break;
		display(ch, a, b);
		while (getchar() != '\n')
			continue;
		printf("Введите еще один символ и 2 целых числа;\n");
		printf("для завершения введите символ новой строки.\n");
	}
	printf("Программа завершена.\n");

	return 0;
}

void display (char ch, int n, int m)
{
	int row, col;

	for (row = 1; row <= n; row++)
	{
		for (col = 1; col <= m; col++)
			putchar(ch);
		putchar('\n');
	}
}
