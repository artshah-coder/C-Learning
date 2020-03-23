// 7b.c -- программа поочередного вывода в stdout строк двух файлов, принимающая аргументы командной строки
#include<stdio.h>
#include<stdlib.h>

int main (int argc, char ** argv)
{
	char ch1, ch2;	// переменные для посимвольного чтения файлов
	FILE * file1, * file2;
	char * str = (char *) malloc(sizeof(char));
	if (NULL == str)
	{
		fprintf(stderr, "Ошибка при выделении памяти.\n");
		exit(EXIT_FAILURE);
	}
	int i;

	if (argc != 3)
	{
		fprintf(stderr, "Использование: %s имя_файла_1 имя_файла_2.\n", *argv);
		exit(EXIT_FAILURE);
	}

	if ((file1 = fopen(*(argv + 1), "r")) == NULL || (file2 = fopen(*(argv + 2), "r")) == NULL)
	{
		fprintf(stderr, "Ошибка при чтении файла %s.\n", file1 == NULL ? *(argv + 1) : *(argv + 2));
		exit(EXIT_FAILURE);
	}
	
	while ((ch1 = getc(file1)) != EOF | (ch2 = getc(file2)) != EOF)
	{
		i = 0;
		while (ch1 != '\n' && ch1 != EOF)
		{
			str = (char *) realloc(str, sizeof(char)*(++i + 1));
			if (NULL == str)
			{
				fprintf(stderr, "Ошибка при выделении памяти.\n");
				exit(EXIT_FAILURE);
			}
			*(str + i - 1) = ch1;
			ch1 = getc(file1);
			if (ch1 == '\n' || ch1 == EOF)
			{
				*(str + i) = '\0';
				if (ch2 == EOF)
					printf("%s\n", str);
				else
					printf("%s ", str);
			}
		}

		i = 0;
		while (ch2 != '\n' && ch2 != EOF)
		{
			str = (char *) realloc(str, sizeof(char)*(++i + 1));
			*(str + i - 1) = ch2;
			ch2 = getc(file2);
			if(ch2 == '\n' || ch2 == EOF)
			{
				*(str + i) = '\0';
				puts(str);
			}
		}
	}

	if (fclose(file1) || fclose(file2))
		fprintf(stderr, "При закрытии файлов %s %s возникли ошибки.\n", *(argv + 1), *(argv + 2));
	free(str);
	puts("Программа завершена.");

	return 0;
}
