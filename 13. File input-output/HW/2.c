// 2.c -- упр. 2, стр. 561. Программа копирования содержимого одного файла в другой файл
// Интерфейс командной строки
#include<stdio.h>
#include<stdlib.h>

int main (int argc, char * argv[])
{
	char ch;
	FILE * src, * dst;

	// проверка корректности аргументов командной строки
	if (argc != 3)
	{
		fprintf(stderr, "Использование: %s [source file] [destination file].\n", *argv);
		exit(EXIT_FAILURE);
	}

	// открытие файла для чтения
	if ((src = fopen(*(argv + 1), "rb")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s для чтения.\n", *(argv + 1));
		exit(EXIT_FAILURE);
	}
	
	// открытие файла для записи
	if ((dst = fopen(*(argv + 2), "wb")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s для записи.\n", *(argv + 2));
		exit (EXIT_FAILURE);
	}

	while (fread (&ch, sizeof(char), 1, src) > 0)
		fwrite(&ch, sizeof(char), 1, dst);
	
	// закрытие файлов
	if (fclose(src))
		fprintf(stderr, "Ошибка при закрытии файла %s.\n", *(argv + 1));
	if (fclose(dst))
		fprintf(stderr, "Ошибка при закрытии файла %s.\n", *(argv + 2));
	
	puts("Программа завершена.");

	return 0;
}
