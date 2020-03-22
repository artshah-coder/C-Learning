#include<stdio.h>
#include<stdlib.h>

int main (int argc, char * argv[])
{
	size_t bytes;
	double value;
	double total = 0.0;
	double med;
	int count = 0;
	FILE * fp;

	switch (argc)
	{
		case 1:
			printf("Введите одно за другим вещественные числа, среднее арифметическое которых вы хотели бы узнать"
					"(для завершения программы введите q):\n");
			while (scanf("%lf", &value) == 1)
			{
				total += value;
				count++;
			}
			if (count > 0)
			{
				med = total/count;
				printf("Среднее значение введенных чисел: %g\n", med);
			}
			else
				printf("Допустимые данные отсутствуют.\n");
			break;
		case 2:
			if ((fp = fopen(*(argv + 1), "rb")) == NULL)
			{
				fprintf(stderr, "Не удалось открыть файл %s на чтение.\n", *(argv + 1));
				exit(EXIT_FAILURE);
			}
			while ((bytes = fread(&value, sizeof (double), 1, fp)) > 0)
			{
				total += value;
				count++;
			}
			if (count > 0)
			{
				med = total/count;
				printf("Среднее значение чисел из файла %s: %g\n", *(argv + 1), med);
			}
			else
				printf("Допустимые данные отстутствуют.\n");
			break;
		default:
			printf("Использование: %s (для чтения stdin) или %s имя_файла (для чтения файла).\n", *argv, *argv);
			break;
	}
	puts("Программа завершена.");

	return 0;
}
