/* paint.c -- использование условной операции */
#include<stdio.h>
#define COVERAGE 350

int main(void)
{
	int sq_feet;
	int cans;

	printf("Введите количество футов, которое необходимо покрасить:\n");
	while(scanf("%d", &sq_feet) == 1)
	{
		cans = sq_feet/COVERAGE;
		cans += (sq_feet%COVERAGE == 0)?0:1;
		printf("Для покраски %d футов потребуется %d %s краски\n", sq_feet, cans, (cans == 1)?"банка":"банки");
		printf("Введите следующее значение для площади покраски (q - для выхода):\n");
	}

	return 0;
}
