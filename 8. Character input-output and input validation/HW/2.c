/* 2.c -- программа, выводящая символы из stdin и их ASCII коды */
#include<stdio.h>

int main (void)
{
	char ch;
	int i = 0; // переменная для подсчета количества выведенных символов

	printf("Введите символы. Чтобы завершить программу, "
			"сэмулируйте конец файла путем нажатия ^D:\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch < ' ')
			switch(ch)
			{
				case '\n':
					printf("\\n - %d ", ch);
					i++;
					break;
				case '\t':
					printf("\\t - %d ", ch);
					i++;
					break;
				default:
					printf("^%c - %d ", ch+64, ch);
					i++;
					break;
				
			}
		else
		{
			printf("%c - %d ", ch, ch);
			i++;
		}
		if(i%10 == 0 || ch == '\n')
			putchar('\n');
	}

	return 0;
}
