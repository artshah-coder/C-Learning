// 8.c -- программа драйвер для функции string_in(), проверяющей, содержится ли вторая строка в первой, упр. 7, стр. 477
#include<stdio.h>
#include<string.h>
#define SZ 513 // длина строки

char * string_in (char * s1, char * s2);
char * s_gets (char * st, int sz);

int main (void)
{
	char s1 [SZ];
	char s2 [SZ];
	printf("Программа проверяет, содержится ли строка s2 в строке s1 (обе строки - не более %d символов).\n", SZ - 1);
	printf("Введите строку s1 (или Enter в начале строки для завершения программы):\n");
	while (s_gets(s1, SZ) && *s1 != '\0')
	{
		printf("Введите строку s2 (или Enter в начале строки для завершения программы):\n");
		s_gets(s2, SZ);
		if (string_in(s1, s2))
			printf("Строка %s содержится в строке %s: " "string_in(s1, s2): %s\n", s2, s1, string_in (s1, s2));
		else
			printf("Строка %s отсутствует в строке %s\n", s2, s1);
		printf("Введите строку s1 (или Enter в начале строки для завершения программы):\n");
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

char * string_in (char * s1, char * s2)
{
	char * ret_val = NULL;
	int i = 1;
	if (*s2 != '\0' && *s1 != '\0')
	{
		while (*s1)
		{	
			while (*s1 != *s2 && *s1)
				s1++;
			if (*s1 == *s2)
			{
				while (*(s1 + i) == *(s2 + i))
					i++;
				if(*(s2 + i) == '\0')
					return ret_val = s1;
				else
					s1++;
			}
		}
	}

	return ret_val;
}
