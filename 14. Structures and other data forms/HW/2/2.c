// 2.c - программа, запрашивающая у пользователя ввода дня, месяца и года
// и возвращающая количество дней от момента Нового Года до введенного пользователем дня
// включительно
#include<stdio.h>
#include<string.h>	// для strcmp()
#include<stdlib.h>	// для exit()
#include"months.h"	// кастомный файл прототипов и определений/объявлений структур

int main (void)
{
	DATE input;		// структура для хранения даты, введенной пользователем
	char ans[MNTHL];	// строка для хранения сохранения месяца, введенного пользователем в буквенном виде
	int i_ans = 0;		// переменная для хранения номера месяца, введенного пользователем в числовом виде
	int total = 0;		// количество дней с Нового Года до введенной пользователем даты
	int i;
	printf("Программа считает количество дней от Нового Года до введенной вами даты.\n");
	printf("Введите день, месяц и год:\n");
	while (scanf("%d", &input.day) != 1 || 
			(scanf("%d", &i_ans) != 1 && scanf("%s", ans) != 1) ||
			scanf("%d", &input.year) != 1) 	// пока не введен корректный формат, читаем ввод
	{
		printf("Некорректный ввод!\nВведите день, месяц, год:\n");
		eatline();	// очищаем входной поток от лишних символов
	}

	if (input.year < 0 || input.day < 1 || input.day > 31)
	{
		fprintf(stderr, "Введена невалидная дата!\n");
		exit(EXIT_FAILURE);
	}
	
	if (i_ans == 0)
	{
		strcpy(input.month.name, ToLower(ans));
		if (input.year%4)
		{
			for (i = 0; i < 12; i++)
				if (strcmp(input.month.name, ToLower(yr[i].name)) == 0 ||
						strcmp(input.month.name, ToLower(yr[i].abbr)) == 0)
					break;
			if (i < 12)
			{
				for (int j = 0; j < i; j++)
					total += yr[j].days;
				if (input.day <= yr[i].days)
					total += input.day;
				else
				{
					fprintf(stderr, "Введена невалидная дата!\n"
						"Такого дня в месяце %s %d года не существует.\n",
						input.month.name, input.year);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				fprintf(stderr, "Введена невалидная дата!\n"
						"Введенного вами месяца не существует.\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			for (i = 0; i < 12; i++)
				if (strcmp(input.month.name, ToLower(bis_yr[i].name)) == 0 ||
						strcmp(input.month.name, ToLower(bis_yr[i].abbr)) == 0)
					break;
			if (i < 12)
			{
				for (int j = 0; j < i; j++)
					total += bis_yr[j].days;
				if (input.day <= bis_yr[i].days)
					total += input.day;
				else
				{
					fprintf(stderr, "Введена невалидная дата!\n"
							"Такого дня в месяце %s %d года не существует.\n",
							input.month.name, input.year);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				fprintf(stderr, "Введена невалидная дата!\n"
						"Введенного вами месяца не существует.\n");
				exit(EXIT_FAILURE);
			}
		}


	}
	else if (i_ans < 1 || i_ans > 12)
	{
		fprintf(stderr, "Введена невалидная дата!\n"
				"Введенного вами месяца не существует.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		input.month.mnumr = i_ans;
		if (input.year%4)
		{
			for (i = 0; i < input.month.mnumr - 1; i++)
				total += yr[i].days;
			if (input.day <= yr[i].days)
				total += input.day;
			else
			{
				fprintf(stderr, "Введена невалидная дата!\n"
						"Такого дня в месяце %d %d года не существует.\n",
						input.month.mnumr, input.year);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			for (i = 0; i < input.month.mnumr - 1; i++)
				total += bis_yr[i].days;
			if (input.day <= bis_yr[i].days)
				total += input.day;
			else
			{
				fprintf(stderr, "Введена невалидная дата!\n"
						"Такого дня в месяце %d %d года не существует.\n",
						input.month.mnumr, input.year);
			}
		}
	}
	
	printf("Дней от Нового Года до введенной вами даты: %d.\n", total);
	puts("Программа завершена.");

	return 0;
}
