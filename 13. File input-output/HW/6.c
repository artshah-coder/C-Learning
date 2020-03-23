// 6.c -- программа, копирующая каждый третий символ из одного файла в другой файл
// работает в интерактивном режиме, чем и отличается от программы из листинга 13.2, работающей в режиме командной строки
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char * input = (char *) malloc(sizeof(char));	// указатели на строки в куче, хранящие имена входного и выходного файлов
	if (NULL == input)	// проверяем, выделилась ли память
	{
		fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
		exit(EXIT_FAILURE);
	}
	
	char * output = (char *) malloc(sizeof(char));
	if (NULL == output)	// проверяем, выделилась ли память
	{
		fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
		exit(EXIT_FAILURE);
	}
	char ch; // переменная для хранения считанных символов
	FILE * in, * out; // входной и выходной файл
	int i = 0;

	printf("Программа копирует каждый третий символ входного файла в выходной файл.\n"
			"Введите имя входного файла и нажмите Enter:\n");
	while ((ch = getchar()) != '\n') // чтение имени входного файла и сохранение его в куче
	{
		input = (char *) realloc(input, sizeof(char)*(++i + 1));
		if (NULL == input)	// проверяем, выделилась ли память
		{
			fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
			exit(EXIT_FAILURE);
		}
		*(input + i - 1) = ch;
	}
	*(input + i) = '\0';
	
	output = (char *) realloc(output, strlen(input) + sizeof(char)*5); // выделение памяти под хранение имени выходного файла
	if (NULL == output)	// проверяем, выделилась ли память
	{
		fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
		exit(EXIT_FAILURE);
	}
	
	strcpy(output, input);
	strcat(output, ".red");

	if ((in = fopen(input, "r")) == NULL)	// попытка открытия файла на чтение
	{
		fprintf(stderr, "Ошибка при открытии файла %s на чтение.\n", input);
		exit(EXIT_FAILURE);
	}

	if ((out = fopen(output, "w")) == NULL)	// попытка открытия файла на запись
	{
		fprintf(stderr, "Ошибка при открытии файла %s на запись.\n", output);
		exit(EXIT_FAILURE);
	}

	i = 0;
	while ((ch = getc(in)) != EOF)	// посимвольное чтение файла in и запись каждго третьего символа в файл out
		if((i++)%3 == 0)
			putc(ch, out);
	if (fclose(in) || fclose(out)) // если возникли ошибки при закрытии одного из файлов - выводим их в stderr
		fprintf(stderr, "Ошибка при закрытии одного из файлов.\n");
	printf("Программа завершена. Сформирован выходной файл %s.\n", output);
	free(input);	// освобождаем память в куче, хранящую названия файлов
	free(output);

	return 0;
}
