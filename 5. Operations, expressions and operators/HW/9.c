#include<stdio.h>

void Temperatures (double f);

int main (void)
{
	double f;
	printf("Программа переводит введенное с клавиатуры значение температуры по шкале Фаренгейта"
			" в значение по шкале Цельсия и шкале Кельвина\n");
	printf("Введите значение температуры по шкале Фаренгейта:\n");
	while (scanf ("%lf", &f) == 1)
	{
		Temperatures(f);
		printf("Введите новое значение температуры по шкале Фаренгейта (нечисловое значение - для завершение программы):\n");
	}

	return 0;
}

void Temperatures (double f)
{
	const double CKOEFF = 5.0/9.0;
	const double CDRIFT = 32.0;
	const double KDRIFT = 273.16; 
	printf("Температура %.2lf по шкале Фаренгейта соответствует %.2lf по шкале Цельсия и %.2lf по шкале Кельвина\n", f, CKOEFF*(f-CDRIFT), CKOEFF*(f-CDRIFT) + 273.16);
}
