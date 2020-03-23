#include<stdio.h>
#include"students.h"

int setgrades (STUDENT * s, int n)
{
	int input;
	printf("Выберите, кому вы хотите проставить оценки по дисциплине Computer Science:\n");
	for (int i = 0; i < n - 1; i += 2)
		printf("%d - %s %s	%d - %s %s\n", i + 1, (s + i)->name.name, (s + i)->name.surname,
				i + 2, (s + i + 1)->name.name, (s + i + 1)->name.surname);
	while (scanf("%d", &input) != 1 || (input < 1 || input > n))
	{
		printf("Ошибка!\nВведите целое число от 1 до %d:\n", n);
		eatline();
	}
	printf("Вы выбрали %s %s. Отличный выбор!\n"
			"Оцените его (её) знания Computer Science %d оценками\n"
			"в вещественном неотрицательном формате:\n",
			(s + input - 1)->name.name, (s + input - 1)->name.surname,
			GRADES);
	for (int i = 0; i < GRADES; i++)
	{
		printf("%d оценка: ", i + 1);
		while (scanf("%f", &(s + input - 1)->grade[i]) != 1 || (s + input - 1)->grade[i] < 0)
		{
			printf("Неверный формат! Пожалуйста, повторите ввод для %d-й оценки.\n"
					"Должна быть вещественная, неотрицательная.\n", i + 1);
			eatline();
		}
		eatline();
	}
	return input - 1;
}

void setavg (STUDENT * s)
{
	s->average = 0.0;
	for (int j = 0; j < GRADES; j++)
		s->average += s->grade[j];
	s->average /= GRADES;	       
}

void printinfo (STUDENT * s)
{
	printf("%s%10s%s%10s", s->name.surname, " ", s->name.name, " ");
	for (int j = 0; j < GRADES; j++)
		printf("%5.2f%3s", s->grade[j], " ");
	printf("AVG: %5.2f\n", s->average);
}

float grdavg (STUDENT * s, int n)
{
	float sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += (s + i)->average;
	return sum/n;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}
