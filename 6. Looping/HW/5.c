// 5.c -- упр. 5, стр. 244 - вложенные циклы 4
#include<stdio.h>

int main (void)
{
	char ch;
	int i, j, k, l;
	
	printf("Программа выводит на экран пирамиду символов.\n"
	       "Вам следует ввести прописную латинскую букву для построения пирамиды.\n");
	scanf("%c", &ch);
	while (!(ch >= 'A' && ch <= 'Z'))
		scanf("%c", &ch);

	printf("Отлично, вы ввели %c\n", ch);
	printf("Пирамида:\n");

	for (i = 0; i <= ch - 'A'; i++)
	{
		for (j = 0; j < ch - 'A' - i; j++)
			printf(" ");
		for (k = 0; k < i+1; k++)
			printf("%c", 'A' + k);
		for (l = k-2; l >= 0; l--)
			printf("%c", 'A' + l);
		printf("\n");
	}
		
	return 0;
}
