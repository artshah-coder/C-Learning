// 9.c -- упр. 9, стр. 528. Программа запрашивает количество слов, считывает их и выводит. Динамическое управление памятью
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main (void)
{
	int words = 0; // переменная, хранящая количество слов, которое хочет ввести пользователь
	char ** array; // динамический массив указателей на char. Размерность массива задается пользователем через переменную words, массив хранит введенные слова 
	char * word; // указатель на строки в куче, в которые будут помещаться введенные слова 
	char buf = ' '; // переменная-буфер, необходимая для отслеживания границ слов (хранит пробельные символы)
	char cur; // переменная для чтения текущей буквы в слове
	int count = 0; // переменная-счетчик для подсчета количества считанных слов
	printf("Сколько слов вы хотите ввести? ");
	while (scanf("%d", &words) != 1 || words < 1)
	{
		while (getchar() != '\n')	// цикл для очистки буфера -- вычитываем символы из буфера до тех пор пока не встретим перенос строки
			continue;
		puts("Ваш ввод некорректен. Повторите: ");
	}
	
	while (getchar() != '\n')	// опять же очищаем буфер, чтобы лишние введенные символы не попали в целевой массив
		continue;

	array = (char **) malloc (words*sizeof(char *)); // выделяем память в куче для хранения массива указателей на char
	
	if (NULL == array)	// проверяем, выделилась ли память
	{
		fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Теперь введите %d слов латиницей:\n", words);
	while(count != words)
	{
		while (isspace(buf) && isspace(cur = getchar()))
				buf = cur;
		count++;
		word = (char *) malloc (sizeof(char) + 1);
		
		if (NULL == word)	// проверяем, выделилась ли память
		{
			fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
			exit(EXIT_FAILURE);
		}
		
		*word = cur;
		*(word + 1) = '\0';
		while (!isspace(cur = getchar()))
		{
			int strl = strlen(word);
			word = (char *) realloc (word, strl + 1);
			
			if (NULL == word)	// проверяем, выделилась ли память
			{
				fprintf(stderr, "Ошибка при динамическом выделении памяти.\n");
				exit(EXIT_FAILURE);
			}
			
			*(word + strl) = cur;
			*(word + strl + 1) = '\0';
		}
		*(array + count - 1) = word;
		buf = cur;
	}
	printf("Вот введенные вами слова:\n");
	for (int i = 0; i < words; i++)
		puts(*(array + i));
	
	free(word);	// освобождаем выделенную в куче память
	free(array);

	return 0;
}
