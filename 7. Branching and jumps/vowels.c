// vowels.c -- использование множества меток в операторе switch
#include<stdio.h>

int main (void)
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;

	a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	printf("Введите текст или # для завершения программы.\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case 'a' :
			case 'A' :
				   a_ct++;
				   break;
			case 'e' :
			case 'E' :
				   e_ct++;
				   break;
			case 'i':
			case 'I':
				   i_ct++;
				   break;
			case 'o':
			case 'O':
				   o_ct++;
				   break;
			case 'u':
			case 'U':
				   u_ct++;
				   break;
			default:
				   break;
		}
	}
	printf("Количество гласных:	A	E	I	O	U\n");
	printf("		%8d %8d %8d %8d %8d\n", a_ct, e_ct, i_ct, o_ct, u_ct);

	return 0;
}
