// pe12-2a.c
// компилировать вместе с pe12-2b.c
#include<stdio.h>
//#include"pe12-2a.h"

void set_mode (int m, int * mode)
{
	if (m == 0 || m == 1)
		*mode = m;
	else
		printf("Указан недопустимый режим. Используется режим %d (%s).\n", *mode, *mode ? "американский" : "метрический");
}

void get_info (int * distance, float * petrol, int * mode)
{
	switch (*mode)
	{
		case 0:
			printf("Введите пройденное расстояние в километрах: ");
			scanf("%d", distance);
			printf("Введите объём израсходованного топлива в литрах: ");
			scanf("%f", petrol);
			break;
		case 1:
			printf("Введите пройденное расстояние в милях: ");
			scanf("%d", distance);
			printf("Введите объём израсходованного топлива в галлонах: ");
			scanf("%f", petrol);
			break;
		default:
			printf("Неизвестная ошибка!\n");
			break;
	}
}

void show_info (int * distance, float * petrol, int * mode)
{
	switch (*mode)
	{
		case 0:
			printf("Расход топлива составляет %.2f литров на 100 км\n", *petrol*100/(*distance));
			break;
		case 1:
			printf("Расход топлива составляет %.1f мили на галлон.\n", *distance/(*petrol));
			break;
		default:
			printf("Неизвестная ошибка!\n");
			break;
	}
}
