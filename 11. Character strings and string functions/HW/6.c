// 6.c -- программа-драйвер для функции is_within(), проверяющей, содержится ли символ в строке
#include<stdio.h>
#include<string.h>
#define SZ 513 // максимальная длина вводимой строки

int is_within (char, char *); // ищет символ в строке, возвращает 1 в случае успеха и 0 в противном случае

int main (void)
{
	char st [SZ];
	char c;
	printf("Программа поиска символа в строке\n");
	printf("Введите строку на латинице, длины не более %d (или Enter в начале строки для завершения программы):\n", SZ-1);
	while (fgets(st, SZ, stdin) && *st != '\n')
	{
		if (strlen(st) == SZ - 1 && *(st + strlen(st) - 1) != '\n')
			while (getchar() != '\n')
				continue;
		if (*(st + strlen(st) - 1) == '\n')
			*(st + strlen(st) - 1) = '\0';
		puts("Теперь введите символ, наличие которого в строке вы хотите проверить:");
		c = getchar();
		while (getchar() != '\n')
			continue;
		if (is_within (c, st))
			printf("Символ %c найден в строке \"%s\"\n", c, st);
		else
			printf("Символ %c отсутствует в строке \"%s\"\n", c, st);
		puts("Введите новую строку (или Enter в начале строки для выхода):");
	}
	puts("Программа завершена!");

	return 0;
}

int is_within (char c, char * string)
{
	while (*string)
		if (*string++ == c)
			return 1;
	return 0;
}
