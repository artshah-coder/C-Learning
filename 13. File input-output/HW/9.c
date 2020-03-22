// 9.c -- модификация программы addawords.c из листинга 13.3 - нумерация добавляемых слов
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41

int main(void)
{
	char words[MAX];
	FILE * fp;
	int count = 0;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Не удается открыть файл \"wordy\".\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	while (fgets(words, MAX, fp))
		count++;

	puts("Введите слова для добавления в файл; для завершения");
	puts("введите символ # в начале строки.");
	while ((fscanf(stdin, "%40s", words) == 1) && (*words != '#'))
	{
		fprintf(fp, "%d.%s\n", ++count, words);
	}

	puts("Содержимое файла:");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Готово!");
	if (fclose(fp))
		fprintf(stderr, "Ошибка при закрытии файла.\n");

	return 0;
}
