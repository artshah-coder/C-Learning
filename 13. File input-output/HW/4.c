/* 4.c -- программа последовательно выводит на экран файлы, указанные в аргументах командной строки */
#include<stdio.h>
#include<stdlib.h>

int main (int argc, char ** argv)
{
	int i = 1;
	char ch;
	FILE * fp;

	if (argc < 2)
	{
		fprintf(stderr, "Использование: %s имя_файла_1 имя_файла_2 имя_файла_3 . . . имя_файла_n.\n", *argv);
		exit(EXIT_FAILURE);
	}

	while (i < argc)
	{
		if ((fp = fopen(*(argv + i), "r")) == NULL)
		{
			fprintf(stderr, "Не удалось открыть файл %s.\n", *(argv + i++));
			continue;
		}

		printf("Содержимое файла %s:\n", *(argv + i));
		while ((ch = getc(fp)) != EOF)
			putchar(ch);
		if (fclose(fp))
			fprintf(stderr, "Ошибка при закрытии файла %s.\n", *(argv + i));
		i++;
	}

	return 0;
}
