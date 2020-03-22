// minimal.c -- упр. 9, стр. 364. Вывод меню и получение корректного ответа от пользователя
#include<stdio.h>

void menu (void);
int get_input (int, int);

int main (void)
{
	menu();
	get_input(1, 4);
	return 0;
}

void menu (void)
{
	printf("Выберите один из следующих вариантов:\n"
			"1) копировать файлы	2) переместить файлы\n"
			"3) удалить файлы		4) выйти из программы\n"
			"Введите номер выбранного варианта:\n");
}

int get_input (int min, int max)
{
	int input, status = 1;
	while ((status = scanf("%d", &input)) == 1 && ( input < min || input > max))
		menu();
	if(!status)
		input = max;
	
	return input;
}
