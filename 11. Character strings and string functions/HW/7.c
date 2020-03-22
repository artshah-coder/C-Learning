// 7.c -- программа драйвер для версии strncpy(), упр. 7, стр. 477
#include<stdio.h>
#include<string.h>
#define SZ1 257 // длина целевой строки
#define SZ2 6 // максимальная длина вводимой строки

char * mystrcpy (char * s1, const char * s2, int n);
char * s_gets (char * st, int sz);

int main (void)
{
	char s1 [SZ1];
	char s2 [SZ2];
	printf("Программа копирует строку s2 в строку s1.\n");
	printf("Введите строку s2 (или Enter в начале строки для завершения программы):\n");
	while (s_gets(s2, SZ2) && *s2 != '\0')
	{
		mystrcpy (s1, s2, (SZ1 - 1 > strlen(s2)) ? strlen(s2) : SZ1 - 1);
		puts("Целевая строка s1:");
		puts(s1);
		printf("Введите строку s2 (или Enter в начале строки для завершения программы):\n");
	}
	puts("Программа завершена!");

	return 0;
}

char * s_gets (char * st, int sz)
{
	if (fgets (st, sz, stdin))
		if (*(st + strlen(st) - 1) == '\n')
			*(st + strlen(st) - 1) = '\0';
		else
			while(getchar() != '\n')
				continue;
	return st;
}

char * mystrcpy (char * s1, const char * s2, int n)
{
	int i;
	for (i = 0; i < n && i < strlen(s2); i++)
		*(s1 + i) = *(s2 + i);
	*(s1 + i) = '\0';
	return s1;
}
