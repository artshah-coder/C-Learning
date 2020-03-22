// partb.c -- остальная часть программы
// компилировать вместе с parta.c
#include<stdio.h>

extern int count; // ссылочное объявление, внешнее связывание

static int total = 0; // статическое определение, внутреннее связывание
void accumulate (int k); // прототип

void accumulate (int k) // k имеет область видимости в пределах блока, связывание отсутствует
{
	static int subtotal = 0;
	if (k <= 0)
	{
		printf("Итерация цикла: %d\n", count);
		printf("subtotal: %d; total: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}

}
