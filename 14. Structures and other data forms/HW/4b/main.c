#include<stdio.h>
#include"insurance.h"

int main (void)
{
	INSR  insurances [5] = {
		{12345, {"Artyom", "Olegovich", "Shahalov"}},
		{123456, {"Daniil", .surname = "Nosov"}},
		{19083, {"Dmitrii", "Vladimirovich", "Glebenkov"}},
		{982109, {"Aleksey", "Andreevich", "Lazarev"}},
		{34871, {"Vadim", .surname = "Snigir"}}
	};
	printf("Застрахованные лица:\n");
	for (int i = 0; i < 5; i++)
		prntstrct(insurances[i]);
	puts("Программа завершена.");
	return 0;
}
