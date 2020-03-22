/* 7.c -- программа считывает символы из stdin и для букв возвращает их порядковый номер в алфавите*/
#include<stdio.h>
#include<ctype.h>

char alph_num (char);

int main (void)
{
	char ch;
	printf("Введите символы (для окончания ввода нажмите ^D):\n");
	while ((ch = getchar()) != EOF)
		if (alph_num(ch) != -1)
			printf("Символ %c является буквой с порядковым номером %d в латинском алфавите.\n", ch, alph_num(ch));
		else
			if (ch <= 32)
				switch(ch)
				{
					case 32:
						printf("Символ 'пробел' не является буквой!\n");
						break;
					case '\n':
						printf("Символ '\\n' не является буквой!\n");
						break;
					case '\t':
						printf("Символ '\t' не является буквой!\n");
						break;
					default:
						printf("Символ ^%c не является буквой!\n", ch+64);
						break;
				}
			else	
				printf("Символ %c не является буквой!\n");

	return 0;
}

char alph_num (char ch)
{
	char num;
	if (isalpha(ch))
		if (islower(ch))
			num = ch - 'a' + 1;
		else
			num = ch - 'A' + 1;
	else
		num = -1;

	return num;
}
