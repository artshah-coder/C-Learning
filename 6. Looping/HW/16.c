// 16.c -- вклады
#include<stdio.h>
#define DAFNA 0.1
#define DEIDRA 0.05
#define SUM 100

int main (void)
{
	double sum1 = SUM, sum2 = SUM; // переменные, хранящие значения сумм на счетах, соответственно, Дафны и Дейтеры
	int years = 0; // переменная, хранящая количество лет, спустя которое сумма на счету Дейтеры превзойдет сумму на счету Дафны
	do
	{
		sum1 += SUM*DAFNA;
		sum2 *= 1 + DEIDRA;
		years++;
	}
	while(sum1 > sum2);
	
	printf("Суммана счету Дейры: %lf.\nСумма на счету Дафны: %lf.\n"
			"Это произойдет через %d лет.\n", sum2, sum1, years);

	return 0;
}


