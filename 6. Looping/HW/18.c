// 18.c -- количество друзей в социальных сетях
#include<stdio.h>
#define D 150 // число Данбара
#define FRS 5 // начальное количество друзей

int main (void)
{
	int friends = FRS; // переменная для хранения числа друзей в конце каждой недели
	int count = 0; // переменная-счетчик недель

	printf("Программа вычисляет количество друзей в соцсетях\n"
			"в конце каждой недели.\n"
			"Программа продолжает подсчет пока количество друзей не превысит\n"
			"число Данбара.\n");
	
	printf("Неделя Количество друзей\n"
			"%3d%10d\n", count, friends);
	while (friends <= D)
	{
		friends *= 2;
		count++;
		printf("%3d%10d\n", count, friends);
	}

	return 0;
}