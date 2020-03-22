// 4.c -- Упр. 4, стр. 291 -- замена символов в введенной строке
#include<stdio.h>

int main (void)
{
	char ch;
	unsigned int sb_ct = 0;
	printf("Введите символы (# - выход):\n");

	while ((ch = getchar()) != '#')
	{
		if (ch == '.')
		{	
			ch = '!';
			putchar(ch);
			sb_ct++;
		}
		else if (ch == '!')
		{
			putchar(ch);
			putchar('!');
			sb_ct++;
		}else
			putchar(ch);
	}
	printf("\nПроизведено замен '.' на '!' и '!' на '!!': %d", sb_ct);

	return 0;
}
