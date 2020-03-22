// 3.c -- интерактивная программа копирования файлов и перевода содержимого в верхний регистр
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void cptoupper(FILE *, FILE *); // функция, выполняющая копирование содержимого первого файла во второй файл в верхнем регистре

int main (void)
{
	FILE * src, * dst;
	int i = 0;	// переменная для организации динамического выделения памяти для хранения имен файлов
	char ch;	// переменная для хранения симолов в процессе чтения файлов
	char * name_src = (char *) malloc (sizeof(char)); // имя файла-источника
	char * name_dst = (char *) malloc (sizeof(char)); // имя файла-назначения
	printf("Программа копирует исходный файл в выходной файл, переводя каждый символ в верхний регистр.\n"
			"Введите имя файла-источника и нажмите Enter:\n");
	
	while ((ch = getchar()) != '\n')	// считывание имени файла-источника и формирование строки с этим именем
	{
		name_src = (char *) realloc (name_src, ++i + 1);
		*(name_src + i - 1) = ch;
	}
	*(name_src + i) = '\0';

	if ((src = fopen (name_src, "r")) == NULL)	// попытка открытия файла-источника
	{
		fprintf(stderr, "Ошибка при открытии фала-источника.\n");
		exit(EXIT_FAILURE);
	}

	printf("Введите имя файла назначения и нажмите Enter:\n");

	i = 0;

	while ((ch = getchar()) != '\n')	// считывание файла назначения и формирование строки с именем
	{
		name_dst = (char *) realloc(name_dst, ++i + 1);
		*(name_dst + i - 1) = ch;
	}
	*(name_dst + i) = '\0';

	if ((dst = fopen(name_dst, "w")) == NULL)	// попытка открытия файла назначения
	{
		fprintf(stderr, "Ошибка при открытии файла назначния на запись.\n");
		exit(EXIT_FAILURE);
	}

	cptoupper(src, dst);	// вызов функции, выполняющей копирование

	if (fclose(src) || fclose(dst))	// если возникает ошибка при закрытии хотя бы одного файла, сообщать об этом
		fprintf(stderr, "Ошибка при закрытии файлов.\n");

	free(name_src);		// освобождение памяти
	free(name_dst);

	puts("Программа завершена!");

	return 0;
}

void cptoupper(FILE * src, FILE *dst)
{
	char ch;
	while ((ch = getc(src)) != EOF)
		putc(toupper(ch), dst);
}
