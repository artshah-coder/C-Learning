// 3.c -- упр. 3, стр. 477 - чтение первого слова из введенной строки и отбрасывание оставшихся символов
#include<stdio.h>
#include<ctype.h>
#define MAX_SZ 512 // максимальная длина первого слова

void read_word (char *);

int main (void)
{
	char word [MAX_SZ];
	printf("Программа вычитывает первое слово из введенной вами строки.\n");
	puts("Введите строку:");
	read_word (word);
	printf("Первое слово из введенной вами строки: %s.\n", word);

	return 0;
}


void read_word (char * word)
{
	char temp = getchar();

	while (isspace (temp))
		temp = getchar();

	while (!isspace(temp))
	{
		*word++ = temp;
		temp = getchar();
	}	
	*word = '\0';
	if (!isspace(temp))
		while (getchar() != '\n')
			continue;
}
