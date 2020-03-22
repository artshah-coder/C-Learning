// файл с главной функцией программы-драйвера для функции задержки на указанное количество секунд
#include"header.h"

int main (void)
{
	double time;
	printf("Программа-драйвер для функции, выполняющей зацикливание указанное число секунд.\n");
	printf("Введите количество секунд, на которое программа должна \"заснуть\":\n");
	while (scanf("%lf", &time) != 1)
	{
		eatline();
		puts("Некорректный ввод. Повторите!");
	}
	eatline();
	delay_sec(time);
	puts("Программа завершена!");

	return 0;
}

void delay_sec (double val)
{
	double start = clock();								// сохраняем время старта
	if (start != -1)								// если clock() отработала без ошибок
		while (fabs(((double) (clock() - start))/CLOCKS_PER_SEC - val) > 0)	// пока не прошло необходимого количества секунд
			continue;							// продолжаем
	else
		printf("Нет доступа к аппаратному времени.\n");
}
