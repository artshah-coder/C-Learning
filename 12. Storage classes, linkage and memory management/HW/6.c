// 6.c -- программа исследует работу функции rand(), генерирует MAX случайных чисел в диапазоне 1..10 и подсчитывающая количество различных чисел
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000 // количество генерируемых элементов
#define COUNT 10 // количество различных начальных значений для генирации случайых чисел

void set_nums (int);

int main (void)
{
	for (int i = 0; i < COUNT; i++)
	{
		printf("Итерация %d:\n", i+1);
		srand(i);
		set_nums(MAX);
	}

	return 0;
}

void set_nums (int n)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0, count10 = 0;
	for (int i = 0; i < n; i++)
		switch (rand() % 10 + 1)
		{
			case 1:
				count1++;
				break;
			case 2:
				count2++;
				break;
			case 3:
				count3++;
				break;
			case 4:
				count4++;
				break;
			case 5:
				count5++;
				break;
			case 6:
				count6++;
				break;
			case 7:
				count7++;
				break;
			case 8:
				count8++;
				break;
			case 9:
				count9++;
				break;
			case 10:
				count10++;
				break;
		}
	printf("	'1': %3d"
			"	'2': %3d"
			"	'3': %3d"
			"	'4': %3d"
			"	'5': %3d"
			"	'6': %3d"
			"	'7': %3d"
			"	'8': %3d"
			"	'9': %3d"
			"	'10': %3d\n", count1, count2, count3, count4, count5, count6, count7, count8, count9, count10);
}
