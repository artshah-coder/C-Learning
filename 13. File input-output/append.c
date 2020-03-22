/* append.c -- добавление содержимого файлов в файл назначения */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096
#define SLEN 81

static char bufer[BUFSIZE];

void append (FILE *, FILE *);
char * s_gets (char *, int);

int main (void)
{
	FILE * fa, * fs;	// fa для файла назначения, fs для исходного файла
	int files = 0;		// количество добавленных файлов
	char file_app[SLEN];	// имя файла назначения
	char file_src[SLEN];	// имя исходного файла
	size_t bytes;

	puts("Введите имя файла назначения:");
	s_gets(file_app, SLEN);
	if ((fa = fopen(file_app, "a+")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s.\n", file_app);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Не удалось создать выходной буфер.\n", stderr);
		exit(EXIT_FAILURE);
	}

	puts("Введите имя первого исходного файла (или пустую строку для завершения):");
	while (s_gets(file_src, SLEN) && *file_src != '\0')
	{
		if (!strcmp(file_src, file_app))
			fputs("Добавить файл в конец самого себя невозможно.\n", stderr);
		else if ((fs = fopen(file_src, "r")) == NULL)
			fprintf(stderr, "Не удалось открыть файл %s.\n", file_src);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Не удалось создать входной буфер.\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Ощибка при чтении файла %s.\n", file_src);
			if (ferror(fa) != 0)
				fprintf(stderr, "Ошибка при записи файла %s.\n", file_app);
			fclose(fs);
			files++;
			printf("Содержимое файла %s добавлено.\n", file_src);
			puts("Введите имя следующего файла (или пустую строку для завершения):");
		}
	}
	printf("Добавление завершено. Количество добавленных файлов: %d.\n", files);
	rewind(fa);
	setvbuf (stdout, NULL, _IOFBF, BUFSIZE);
	printf("Содержимое файла %s:\n", file_app);
	while ((bytes = fread (bufer, sizeof(char), BUFSIZE, fa)) > 0)
		fwrite (bufer, sizeof(char), bytes, stdout);
	puts("Отображение завершено!");
	fclose(fa);

	return 0;
}

void append (FILE * source, FILE * dest)
{
	size_t bytes;
	while ((bytes = fread (bufer, sizeof(char), BUFSIZE, source)) > 0)
		fwrite (bufer, sizeof(char), bytes, dest);
}

char * s_gets (char * s, int n)
{
	char * find;
	if (fgets(s, n, stdin))
	{
		find = strchr(s, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return s;
}
