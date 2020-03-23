#include<stdio.h>
#include"students.h"

int main (void)
{
	STUDENT students[CSIZE] = {
		{.name = {"Artyom", "Shahalov"}},
		{.name = {"Danila", "Nosov"}},
		{.name = {"Aleksey", "Lazarev"}},
		{.name = {"Dmitriy", "Glebenkov"}}
	};
	int index;
	
	index = setgrades (students, CSIZE);
	setavg (students + index);
	printf("Успеваемость по дисциплине Computer Sciense:\n");
	printinfo (students + index);
	printf("\nСредняя оценка по курсу: %5.2f\n", grdavg (students, CSIZE));
	puts("Программа завершена!");

	return 0;
}
