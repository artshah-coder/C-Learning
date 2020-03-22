// 6.c -- упр. 6, стр. 245 -- вывод квадратов и кубов числа в таблице
#include<stdio.h>

int main (void)
{
	int i, num, down_border, up_border;

	printf("Программа выводит таблицу квадратов и кубов целых чисел.\n"
			"Пожалуйста, задайте нижнюю и верхнюю границу таблицы:\n");
	scanf("%d%d", &down_border, &up_border);
	printf("Нижняя граница таблицы: %d; верхняя граница таблицы: %d\n", down_border<=up_border?down_border:up_border, up_border>=down_border?up_border:down_border);
	
	printf("Число Квадрат числа Куб числа\n");
	for(num = down_border<=up_border?down_border:up_border; num <= (up_border>=down_border?up_border:down_border); num++)
		printf("%5d %7d %10d\n", num, num*num, num*num*num);

	return 0;
}
