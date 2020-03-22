// 10.c -- программа, запрашивающая имя файла и позицию в файле и выводящая в stdout часть строки, начиная с этой позиции
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE * fp;	
	long i = 0;	// переменная для организации произвольного доступа в файл и выделения памяти для хранения строк
	char ch;	// переменная для посимвольного чтения файла и stdin
	char * name = (char *) malloc(sizeof(char));	// имя файла для чтения, память выделяется динамически
	char * string = (char *) malloc(sizeof(char));	// строка из файла, память выделяется динамически
	
	printf("Введите имя файла и нажмите Enter:\n");
	
	while ((ch = getchar()) != '\n' && ch != EOF)	// читаем имя файла, динамически выделяем память под него
	{
		name = (char *) realloc(name, sizeof(char)*(++i + 1));
		*(name + i - 1) = ch;
	}
	*(name + i) = '\0';
	
	if ((fp = fopen(name, "r")) == NULL)	// попытка открытия файла на чтение
	{
		fprintf(stderr, "Ошибка чтения файла %s.\n", name);
		exit(EXIT_FAILURE);
	}

	printf("Введите позицию в файле %s, начиная с которой будет выведена строка файла\n"
	"для завершения программы, введите отрицательное или нечисловое значение:\n", name);
	
	while (scanf("%ld", &i) == 1 && i >= 0)	
	{
		while ((ch = getchar()) != '\n')	// считываем лишние символы из ввода
			continue;
		if (fseek(fp, i, SEEK_SET) == 0)	// если переход в нужную позицию в файле успешен, читаем кусок строки,
							// выделяем под нее память и выводим на эран
		{
			i = 0;
			while ((ch = getc(fp)) != '\n' && ch != EOF)
			{
				string = (char *) realloc(string, sizeof(char)*(++i + 1));
				*(string + i - 1) = ch;
			}
			*(string + i) = '\0';
			printf("Строка, начиная с введенной вами позиции, выглядит так:\n%s\n", string);
		}
		else
			printf("В файле %s позиции %d не существует.\n", name, i);
		printf("Введите позицию в файле %s, начиная с которой будет выведена строка файла\n"
				"для завершения работы программы, введите отрицательное или нечисловое значение:\n", name);
	}
	
	if (fclose(fp) != 0)
		fprintf(stderr, "Ошибка при закрытии файла %s.\n", name);

	free(name);	// освобождаем ранее выделенную память
	free(string);

	puts("Программа завершена!");

	return 0;
}
