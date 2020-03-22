// electric.c -- подсчитывает сумму для счета за электроэнергию
#include<stdio.h>
#define RATE1 0.13230	// тариф за первые 360 кВт/ч
#define RATE2 0.15040	// тариф за следующие 108 кВт/ч
#define RATE3 0.30025	// тариф за следующие 252 кВт/ч
#define RATE4 0.34025	// тариф при превышении расхода 720 кВт/ч
#define BREAK1 360.0	// первая точка разрыва тарифов
#define BREAK2 468.0	// вторая точка разрыва тарифов
#define BREAK3 720.0	// третья точка разрыва тарифов
#define BASE1 RATE1*BREAK1	// стоимость 360 кВт/ч
#define BASE2 BASE1 + RATE2*(BREAK2-BREAK1) // стоимость 468 кВт/ч
#define BASE3 BASE1 + BASE2 + RATE3*(BREAK3-BREAK2) // стоимость 720 кВт/ч

int main (void)
{
	double kwh;	// израсходованные киловат-часы
	double bill;	// сумма к оплате

	printf("Введите объём израсходованной электроэнергии в кВт/ч.\n");
	scanf("%lf", &kwh);
	if (kwh <= BREAK1)
			bill = RATE1*kwh;
	else if (kwh <= BREAK2)
		bill = BASE1 + (kwh - BREAK1)*RATE2;
	else if (kwh <= BREAK3)
		bill = BASE2 + (kwh - BREAK2)*RATE3;
	else
		bill = BASE3 + (kwh - BREAK3)*RATE4;

	printf("Сумма к оплате за %.1lf кВт/ч составляет $%1.2lf.\n", kwh, bill);

	return 0;
}
