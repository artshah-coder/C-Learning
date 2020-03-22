// 8_mod.c -- упр. 9, стр. 245. Операции с вещественными числами в цикле
#include<stdio.h>

double f (double a, double b);

int main (void)
{
	double a, b;
	printf("Программа запрашивает 2 вещественных числа\n"
			"и выводит значение их разности, деленное на их произведение.\n");
	printf("Задайте 2 вещественных числа a и b:\n");
	while (scanf("%lf%lf", &a, &b) == 2)
	{
		printf("Ваш ввод: a = %lf, b = %lf\n"
				"(a-b)/(a*b) = %lf\n", a, b, f(a,b));
		printf("Задайте 2 новых числа:\n");
		
	}
	printf("Похоже, вы ошиблись при вводе. Программа окончена.\n");

	return 0;
}

double f (double a, double b)
{
	return (a-b)/(a*b);
}
