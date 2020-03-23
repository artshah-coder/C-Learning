// 1.c -- упр. 1, стр. 561 -- программа подсчитывает количество символов в файле и печатает его содержимое в stdout
#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	int ch;		// место для хранения каждого считанного символа
	int i = 0;
	FILE * fp;
	char * file = (char *) malloc (sizeof(char));	// имя файла, место для хранения выделяется динамически в куче
	
	if (NULL == file)	// проверяем, выделилась ли память
	{
		fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Программа подсчитывает количество символов в файле и выводит его содержимое на экран.");
	puts("Введите и нажмите Enter:");
	
	while ((ch = getchar()) != '\n')
	{
		file = (char *) realloc (file, sizeof(char)*(++i + 1));
		
		if (NULL == file)	// проверяем, выделилась ли память
		{
			fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
			exit(EXIT_FAILURE);
		}
		
		*(file + i - 1) = ch;
	}
	*(file + i) = '\0';

	if ((fp = fopen(file, "r")) == NULL)	// открываем поток, проверяем успешность операции
	{
		fprintf(stderr, "Не удалось открыть файл.\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (fread(&ch, sizeof(char), 1, fp) > 0)
	{
		fwrite(&ch, sizeof(char), 1, stdout);
		i++;	
	}
	printf("Файл %s содержит %d символов.\n", file, i);
	
	if (fclose(fp))		// закрываем поток с проверкой успешности операции
		fprintf(stderr, "Ошибка при закрытии файла.\n");
	
	return 0;
}
