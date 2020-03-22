// pe12-2a.c
// компилировать вместе с pe12-2b.c
#include<stdio.h>
#include"pe12-2a.h"

static int mode; /* переменная для хранения режима, область видимости в пределах файла,
	    	    внутреннее связывание */
static int distance; /* переменная для хранения расстояния, область видимости в пределах файла,
			внутреннее связывание */
static float petrol; /* переменная для хранения расхода топлива, область видимости в пределах файла,
			внутреннее связывание */
void set_mode (int m)
{
	if(m == 0 || m == 1)
		mode = m;
	else
		printf("Указан недопустимый режим. Используется режим %d (%s).\n", mode, mode == 0 ? "метрический" : "американский");
}

void get_info (void)
{
	switch (mode)
	{
		case 0:
			printf("Введите пройденное расстояние в километрах: ");
			scanf("%d", &distance);
			printf("Введите объём израсходованного топлива в литрах: ");
			scanf("%f", &petrol);
			break;
		case 1:
			printf("Введите пройденное расстояние в милях: ");
			scanf("%d", &distance);
			printf("Введите объём израсходованного топлива в галлонах: ");
			scanf("%f", &petrol);
			break;
		default:
			printf("Неизвестная ошибка!\n");
			break;
	}
}

void show_info (void)
{
	switch (mode)
	{
		case 0:
			printf("Расход топлива составляет %.2f литров на 100 км\n", petrol*100/distance);
			break;
		case 1:
			printf("Расход топлива составляет %.1f мили на галлон.\n", distance/petrol);
			break;
		default:
			printf("Неизвестная ошибка!\n");
			break;
	}
}
