// 8.c -- программа подсчитывает количество вхождений символа в файл. Входные данные передаются через аргументы командной строки
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char ** argv)
{
	FILE * array[argc - 2];	// массив из argc - 2 указателей файлов
	int i;
	int count = 0;
	char ch;
	
	if (argc < 2 || strlen(*(argv + 1)) != 1)
	{
		fprintf(stderr, "Использование: %s символ [файл_1 файл_2 файл_3 ... файл_N]\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
		for (i = 0; i < argc - 2; i++)
			if ((*(array + i) = fopen(*(argv + i + 2), "r")) == NULL)
				fprintf(stderr, "Не удалось открыть файл %s.\n", *(argv + i + 2));
			else
			{
				while ((ch = getc(*(array + i))) != EOF)
					if (ch == **(argv + 1))
						count++;
				printf("Файл %s содержит %d символов %c.\n", *(argv + i + 2), count, **(argv + 1));
				if (fclose(*(array + i)))
					fprintf(stderr, "Ошибка при закрытии файла %s.\n", *(argv + i + 2));
				count = 0;
			}
	else
		while ((ch = getchar()) != EOF)
		{
			if (ch == **(argv + 1))
				count++;
			printf("stdin содержит %d символов %c.\n", count, **(argv + 1));
		}
	puts("Программа завершена.");

	return 0;
}
