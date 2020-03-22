// 12.c -- программа создает и преобразует текстовый файл с цифрами в текстовый файл с символами
#include<stdio.h>
#include<stdlib.h>
#define BORDER 10
#define STRINGS 20
#define COLS 30

int main(void)
{
	FILE * input, * output;
	int array [STRINGS] [COLS];
	char strings [STRINGS] [COLS + 1];
	int i, j;

	if ((input = fopen("input", "w+")) == NULL)
	{
		fprintf(stderr, "Ошибка при открытии входного файла.\n");
		exit(EXIT_FAILURE);
	}

	if ((output = fopen("output", "w")) == NULL)
	{
		fprintf(stderr, "Ошибка при открытии выходного файла.\n");
		exit(EXIT_FAILURE);
	}

	printf("Программа преобразует входные данные в \"изображение\".\n"
			"Входной файл input можно открыть и просмотреть.\n"
			"Также можно просмотреть выходной файл output.\n"
			"Впрочем, его содержимое вы также увидите на экране в ходе выполнения программы.\n");

	for (i = 0; i < STRINGS; i++)
		for (j = 0; j < COLS; j++)
		{
			srand((unsigned int) i + j);
			fprintf(input, "%1d%s", rand() % BORDER, j == COLS - 1 ? "\n" : " ");
		}

	rewind(input);

	for (i = 0; i < STRINGS; i++)
		for (j = 0; j < COLS; j++)
			fscanf(input, "%d", *(array + i) + j);

	for (i = 0; i < STRINGS; i++)
	{
		for (j = 0; j < COLS; j++)
			switch (*(*(array + i) + j))
			{
				case 0:
					*(*(strings + i) + j) = ' ';
					break;
				case 1:
					*(*(strings + i) + j) = '.';
					break;
				case 2:
					*(*(strings + i) + j) = 39;
					break;
				case 3:
					*(*(strings + i) + j) = ':';
					break;
				case 4:
					*(*(strings + i) + j) = '~';
					break;
				case 5:
					*(*(strings + i) + j) =  '*';
					break;
				case 6:
					*(*(strings + i) + j) = '=';
					break;
				case 7:
					*(*(strings + i) + j) = '$';
					break;
				case 8:
					*(*(strings + i) + j) = '%';
					break;
				case 9:
					*(*(strings + i) + j) = '#';
					break;
			}
		*(*(strings + i) + j) = '\0';
	}

	puts("Результат работы программы:");
	for (i = 0; i < STRINGS; i++)
	{
		fprintf(output, "%s\n", *(strings + i));
		puts(*(strings + i));
	}

	puts("\nПрограмма завершена!");

	return 0;
}
