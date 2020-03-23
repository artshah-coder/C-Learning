/* 5_alt.c -- программа, выводящая строки, содержащие целевой символ */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFER 257

//прототип локальной функции
int find_ch (char, char *);	// ищет символ в строке, возвращает 1 при успехе, 0 - в противном случае

int main (int argc, char ** argv)
{
	char line[BUFER];
	FILE * fp;
	if (argc != 3)
	{
		fprintf(stderr, "Использование: %s [символ] [имя файла].\n", *argv);
		exit(EXIT_FAILURE);
	}
	if (strlen(*(argv + 1)) > 1)
	{
		fprintf(stderr, "Второй аргумент должен быть символом.\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(*(argv + 2), "r")) == NULL)
	{
		fprintf(stderr, "Ошибка открытия файла %s.\n", *(argv + 2));
		exit(EXIT_FAILURE);
	}
	printf("Строки из файла %s, содержащие символ %c:\n", *(argv + 2), **(argv + 1));
	while (fgets(line, BUFER, fp) != NULL)
		if (find_ch(**(argv + 1), line))
			fputs(line, stdout);
	if (fclose(fp))
		fprintf(stderr, "Ошибка при закрытии файла %s.\n", *(argv + 2));
	puts("Программа завершена.");

	return 0;
}

int find_ch (char ch, char * s)
{
	while (*s)
		if (ch == *s++)
			return 1;

	return 0;
}
