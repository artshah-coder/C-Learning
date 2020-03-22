// Упр. 8, стр. 156
#include<stdio.h>
#define GTOL 3.785
#define MTOK 1.609

int main(void)
{
	float d, v;
	printf("Введите количество пройденных миль и количество израсходованного бензина в галлонах:\n");
	scanf("%f %f", &d, &v);
	printf("Количество миль, пройденных на одном галлоне горючего: %.1f\n", d/v);
	printf("Расход топлива (л/100км): %.1f\n", (v*GTOL)/(d*MTOK));


	return 0;
}
