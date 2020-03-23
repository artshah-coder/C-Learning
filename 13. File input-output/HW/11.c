// 11.c -- программа, осуществляющая поиск по файлу строк, содержащих указанную
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char ** argv)
{
	FILE * fp;
	char * string = (char *) malloc(sizeof(char));
	if (NULL == string)	// проверяем, выделилась ли память
	{
		fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
		exit(EXIT_FAILURE);
	}
	
	char ch;
	int i = 0;;

	if (argc != 3)
	{
		fprintf(stderr, "Использование: %s строка имя_файла.\n", *argv);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(*(argv + 2), "r")) == NULL)	// открываем файловый поток на чтение
	{
		fprintf(stderr, "Ошибка чтения файла %s.\n", *(argv + 2));
		exit(EXIT_FAILURE);
	}

	printf("Строки из файла %s, содержащие строку %s:\n", *(argv + 2), *(argv + 1));

	while ((ch = getc(fp)) != EOF)
	{
		while (ch != '\n' && ch != EOF)
		{
			string = (char *) realloc(string, sizeof(char)*(++i + 1));
			if (NULL == string)	// проверяем, выделилась ли память
			{
				fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
				exit(EXIT_FAILURE);
			}
			
			*(string + i - 1) = ch;
			ch = getc(fp);
		}
		*(string + i) = '\0';
		i = 0;
		if (strstr(string, *(argv + 1)))
			puts(string);
	}

	if (fclose(fp) != 0)	// закрываем поток с проверкой
		fprintf(stderr, "Ошибка при закрытии файла %s.\n", *(argv + 2));
	free(string);		// освобождаем выделенную память
	puts("Программа завершена!");

	return 0;
}
