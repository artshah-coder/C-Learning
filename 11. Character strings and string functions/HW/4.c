// 3.c -- упр. 3, стр. 477 - чтение первого слова (длины не более n) из введенной строки и отбрасывание оставшихся символов
#include<stdio.h>
#include<ctype.h>

void read_word (char *, int);

int main (void)
{
	int length;
	printf("Программа вычитывает первое слово (длины не более n) из введенной вами строки.\n");
	printf("Задайте максимальную длину слова, которое программа сможет считать:\n");
	scanf("%d", &length);
	while (getchar() != '\n')
		continue;
	char word [length + 1];
	puts("Введите строку:");
	read_word (word, length + 1);
	printf("Первое слово из введенной вами строки (длиной не более %d символов): %s.\n", length, word);

	return 0;
}


void read_word (char * word, int n)
{
	char temp = getchar();
	int i = 0;

	while (isspace (temp))
		temp = getchar();

	while (!isspace(temp) && i < n - 1)
	{
		*(word + i++) = temp;
		temp = getchar();
	}	
	*(word + i) = '\0';
	if (!isspace(temp))
		while (getchar() != '\n')
			continue;
}
