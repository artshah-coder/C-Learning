// Главная функция программы
#include"header.h"

int main (int argc, char * argv[])
{
	char str [CHAR_BIT*sizeof(unsigned int) + 1];

	if (argc != 3)						// проверка количества аргументов командной строки
	{
		fprintf(stderr, "Использование: %s <двоичная строка 1> <двоичная строка 2>.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; *(*(argv + 1) + i) != '\0'; i++)	// проверка корректности первого аргумента
		if (strchr("01", *(*(argv + 1) + i)) == NULL)
		{
			fprintf(stderr, "Некорректный формат строки в аргументе программы.\n"
					"Принимаются только двоичные строки!\n");
			exit(EXIT_FAILURE);
		}

	for (int i = 0; *(*(argv + 2) + i) != '\0'; i++)	// проверка корректности второго аргумента
		if (strchr("01", *(*(argv + 2) + i)) == NULL)
		{
			fprintf(stderr, "Некорректный формат строки в аргументе программы.\n"
					"Принимаются только двоичные строки!\n");
			exit(EXIT_FAILURE);
		}

	printf("Вы ввели: %s и %s.\n", *(argv + 1), *(argv + 2));
	btos(~stob(*(argv + 1)), str);				// операция инверсии битов 1 числа и запись результата в строку str
	printf("Результат ~%s: %s.\n", *(argv + 1), str);
	btos(~stob(*(argv + 2)), str);				// инверсия битов 2 числа и запись результата в str
	printf("Результат ~%s: %s.\n", *(argv + 2), str);
	btos(stob(*(argv + 1)) & stob(*(argv + 2)), str);	// операция & над числами 1 и 2, запись результата в str
	printf("Результат %s & %s: %s.\n", *(argv + 1), *(argv + 2), str);
	btos(stob(*(argv + 1)) | stob(*(argv + 2)), str);	// операция | над битами чисел, запись результата в str
	printf("Результат %s | %s: %s.\n", *(argv + 1), *(argv + 2), str);
	btos(stob(*(argv + 1)) ^ stob(*(argv + 2)), str);	// операция ^ над битами чисел 1 и 2, запись результата в str
	printf("Результат %s ^ %s: %s.\n", *(argv + 1), *(argv + 2), str);

	return 0;
}
