// 5.c -- Упр. 5, стр. 291 - выполнение упражнения 4 с использованием оператора switch
#include<stdio.h>

int main (void)
{
	char ch;
	unsigned int sb_ct = 0;
	
	printf("Введите символы (# - выход):\n");

	while ((ch = getchar()) != '#')
		switch (ch)
		{
			case '.':
				ch = '!';
				sb_ct++;
				putchar(ch);
				break;
			case '!':
				putchar(ch);
				putchar('!');
				sb_ct++;
				break;
			default:
				putchar(ch);
				break;
		}
		
	printf("Произведено замен: %u\n", sb_ct);

	return 0;
}
