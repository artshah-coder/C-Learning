// файл с главной функцией
#include"header.h"

int main (void)
{
	double x, y;
	printf("Введите 2 вещественных числа.\n"
			"q - для выхода.\n");
	while (scanf("%lf%lf", &x, &y) == 2)
	{
		eatline();
		printf("Гармоническое средние чисел %lf и %lf равно %g\n", x, y, HARMAVG(x, y));
		puts("Введите следующую пару вещественных чисел (q - для выхода):");
	}
	eatline();
	puts("Программа завершена!");

	return 0;
}
