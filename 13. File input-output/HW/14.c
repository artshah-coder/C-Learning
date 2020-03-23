// 14.c -- функция обработки помех
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BORDER 10

void noise_processing (int, int, int [*][*]);
//unsigned int abs (int);

int main(void)
{
	FILE * input, * output;
	int COLS = 30, STRINGS = 20;
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
			srand((unsigned int) (i + j + time(NULL)*1000));
			fprintf(input, "%1d%s", rand() % BORDER, j == COLS - 1 ? "\n" : " ");
		}

	rewind(input);

	for (i = 0; i < STRINGS; i++)
		for (j = 0; j < COLS; j++)
			fscanf(input, "%d", *(array + i) + j);

	noise_processing(STRINGS, COLS, array);

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
	
	if (fclose(input))
		fprintf(stderr, "Ошибка при закрытии входного потока.\n");
	if (fclose(output))
		fprintf(stderr, "Ошибка при закрытии выходного потока.\n");

	puts("\nПрограмма завершена!");

	return 0;
}

void noise_processing (int rows, int cols, int array [rows] [cols])
{
	double tmp;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || j == 0)
				if (j == cols - 1)
				{
					if (abs(*(*(array + i) + j) - *(*(array + i) + j - 1)) > 1 && abs(*(*(array + i) + j) - *(*(array + i + 1) + j)) > 1)
					{
						tmp = (*(*(array + i) + j - 1) + *(*(array + i + 1) + j))/2;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				}
				else if (j)
				{
					if (abs(*(*(array + i) + j) - *(*(array + i) + j - 1)) > 1 && abs(*(*(array + i) + j) - *(*(array + i) + j + 1)) > 1 &&
							abs(*(*(array + i) + j) - *(*(array + i + 1) + j)) > 1)
					{
						tmp = (*(*(array + i) + j - 1) + *(*(array + i) + j + 1) + *(*(array + i + 1) + j))/3;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				}
				else if (i == rows - 1)
				{
					if (abs(*(*(array + i) + j) - *(*(array + i) + j + 1)) > 1 && abs(*(*(array + i) + j) - *(*(array + i - 1) + j)) > 1)
					{
						tmp = (*(*(array + i) + j + 1) + *(*(array + i - 1) + j))/2;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				
				}
				else if (i)
				{
					if (abs(*(*(array + i) + j) - *(*(array + i - 1) + j)) > 1 && abs(*(*(array + i) + j) - *(*(array + i + 1) + j)) > 1 &&
							abs(*(*(array + i) + j) - *(*(array + i) + j + 1)) > 1)
					{
						tmp = (*(*(array + i - 1) + j) + *(*(array + i + 1) + j) + *(*(array + i) + j + 1))/3;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				}
				else
				{
					if (abs(*(*(array + i) + j) - *(*(array + i + 1) + j)) > 1 && abs(*(*(array + i) + j) - *(*(array + i) + j + 1)) > 1)
					{	
						tmp = (*(*(array + i + 1) + j) + *(*(array + i) + j + 1))/2;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				}
			else if (i == rows - 1 || j == cols - 1)
				if (j != cols - 1)
				{
					if (abs(*(*(array + i) + j) - *(*(array + i) + j + 1)) > 1 && abs(*(*(array + i) + j) - *(*(array + i) + j - 1)) > 1 &&
							abs(*(*(array + i) + j) - *(*(array + i - 1) + j)) > 1)
					{
						tmp = (*(*(array + i) + j + 1) + *(*(array + i) + j - 1) + *(*(array + i - 1) + j))/3;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				}
				else if (i != rows - 1)
				{
					if (abs(*(*(array + i) + j) - *(*(array + i) + j - 1)) > 1 && abs(*(*(array + i) + j) - *(*(array + i - 1) + j)) > 1 &&
							abs(*(*(array + i) + j) - *(*(array + i + 1) + j)) > 1)
					{
						tmp = (*(*(array + i) + j - 1) + *(*(array + i - 1) + j) + *(*(array + i + 1) + j))/3;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				}
				else
				{
					if (abs(*(*(array + i) + j) - *(*(array + i) + j - 1)) > 1 && abs(*(*(array + i) + j) - *(*(array + i - 1) + j)) > 1)
					{
						tmp = (*(*(array + i) + j - 1) + *(*(array + i - 1) + j))/2;
						*(*(array + i) + j) = (int) tmp + 0.5;
					}
				}
			else
				if (abs(*(*(array + i) + j) - *(*(array + i) + j - 1)) > 1 && abs(*(*(array + i) + j) - *(*(array + i) + j + 1)) > 1 && 
						abs(*(*(array + i) + j) - *(*(array + i - 1) + j)) > 1 && abs(*(*(array + i) + j) - *(*(array + i + 1) + j)) > 1)
				{
					tmp = (*(*(array + i) + j - 1) + *(*(array + i) + j + 1) + *(*(array + i - 1) + j) + *(*(array + i + 1) + j))/4;
					*(*(array + i) + j) = (int) tmp + 0.5;
				}
		}
}

/*unsigned int abs (int a)
{
	if (a < 0)
		a *= -1;
	return (unsigned int) a;
}*/
