/* Упр. 1, стр. 290 1.с -- программа считывает строку и подсчитывает количество пробелов, переводов строки, остальных символов*/
#include<stdio.h>

int main (void)
{
	char ch;
	int sp_ct = 0;
	int nl_ct = 0;
	int o_ct = 0;

	printf("Введите данные (# для завершения ввода):\n");
	while ((ch = getchar()) != '#')
		if (ch == ' ')
			sp_ct++;
		else if (ch == '\n')
			nl_ct++;
		else
			o_ct++;
	
	printf("В вашем вводе было %d пробелов, %d переводов строки и  %d остальных символов\n", sp_ct, nl_ct, o_ct);

	return 0;
}
