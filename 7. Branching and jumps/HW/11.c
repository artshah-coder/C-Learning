// 11.c -- упр. 11, стр. 292 -- компания по поставке овощей
#include<stdio.h>
#define ART 2.05 // цена фунта артишоков
#define BEET 1.15 // цена фунта свеклы
#define CARROT 1.09 // цена фунта моркови
#define SUM 100 // сумма, при превышении которой продавец даёт скидку
#define DIS 0.05 // размер скидки в долях единицы
#define DEL1 6.50 // стоимость доставки веса до W1
#define W1 5 // вес в фунтах
#define DEL2 14.00 // стоимость доставки веса от W1 до W2
#define W2 20 // вес в фунтах
#define ADD 0.50 // дополнительные затраты на доставку с каждого фунта при превышении веса заказа W2

int main (void)
{
	char ch; // переменная для чтения ввода пользователя
	double w; // переменная для чтения ввода веса
	double w_art = 0.0; // вес артишоков
	double w_beet = 0.0; // вес свеклы
	double w_carrot = 0.0; // вес моркови
	double discount = 0.0; // сумма скидка
	double del; // сумма доставки
	
	printf("Доставка овощей.\nПрограмма сформирует полную информацию о вашем заказе.\n");
	printf("Пожалуйста, выберите товар, который вы хотите заказать:\n"
			"a - АРТИШОКИ				b - СВЕКЛА\n"
			"c - МОРКОВЬ				q - ВЫХОД\n");
	while ((ch = getchar()) == 'a' || ch == 'b' || ch == 'c')
	{
		switch (ch)
		{
			case 'a':
				printf("Введите вес артишоков в фунтах, который вы хотите заказать:\n");
				scanf("%lf", &w);
				w_art += w;
				break;
			case 'b':
				printf("Введите вес свеклы в фунтах, который вы хотите заказать:\n");
				scanf("%lf", &w);
				w_beet += w;
				break;
			case 'c':
				printf("Введите вес моркови в фунтах, который вы хотите заказать:\n");
				scanf("%lf", &w);
				w_carrot += w;
				break;
			default:
				break;
		}
		printf("Закажите что-нибудь ещё. Выберите:\n"
				"a - АРТИШОКИ                           b - СВЕКЛА\n"
				"c - МОРКОВЬ                            q - ВЫХОД\n");
	}	

	if (w_art > 0 || w_beet > 0 || w_carrot > 0)
	{
		if (w_art > 0)
			printf("Вы заказали %.2lf фунта артишоков. Цена артишоков: %.2lf $/фунт. Стоимость заказанных артишоков: %.2lf $\n", w_art, ART, w_art*ART);
		if (w_beet > 0)
			printf("Вы заказали %.2lf фунта свеклы. Цена свеклы: %.2lf $/фунт. Стоимость заказанной свеклы: %.2lf $\n", w_beet, BEET, w_beet*BEET);
		if (w_carrot > 0)
			printf("Вы заказали %.2lf фунта моркови. Цена моркови: %.2lf $/фунт. Стоимость заказанной моркови: %.2lf $\n", w_carrot, CARROT, w_carrot*CARROT);
		printf("Общая стоимость заказа: %.2lf $\n", w_art*ART + w_beet*BEET + w_carrot*CARROT);
		if(w_art*ART + w_beet*BEET + w_carrot*CARROT >= SUM)
		{
			discount = DIS*(w_art*ART + w_beet*BEET + w_carrot*CARROT);
			printf("Ваша скидка: %.2lf $\n", discount);
		}
		if (w_art + w_beet + w_carrot <= W1 && w_art + w_beet + w_carrot > 0)
		{
			del = DEL1;
			printf("Стоимость доставки: %.2lf $\n", del);
		}
		else if (w_art + w_beet + w_carrot <= W2 && w_art + w_beet + w_carrot > 0)
		{
			del = DEL2;
			printf("Стоимость доставки: %.2lf $\n", del);
		}
		else if (w_art + w_beet + w_carrot > 0)
		{
			del = DEL2 + ADD*(w_art + w_beet + w_carrot);
			printf("Стоимость доставки: %.2lf $\n", del);
		}
		printf("Итоговая сумма заказа с учетом всех затрат: %.2lf $\n", w_art*ART + w_beet*BEET + w_carrot*CARROT - discount + del);
	}
	printf("Программа завершена. До свидания!\n");

	return 0;
}
