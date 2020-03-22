// example.c -- главная функция
#include"example.h"

inline static void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

int main (void)
{
	int x, y;
	printf("Введите два целых числа.\n"
			"q - для выхода.\n");
	while (scanf("%d%d", &x, &y) == 2)
	{
		eatline();
		printf("Вы ввели %d и %d.\n", x, y);
		printf("Меньшее из чисел: %d\n", MIN(x, y));
		printf("Сумма квадратов этих чисел: %d\n", SUMQ(x, y));
		printf("%d - %s число, %d - %s число\n", x, EVEN(x) ? "четное": "нечетное", y, EVEN(y) ? "четное": "нечетное");
		puts("Введите следующую пару целых чисел (q -для выхода):");
	}
	eatline();
	puts("Программа завершена.");

	return 0;
}
