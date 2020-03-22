/* loc_stat.c -- использование локальной статической переменной */
#include<stdio.h>

void trystat (void);

int main (void)
{
	int count;
	for (count = 1; count <= 3; count++)
	{
		printf("Начинается итерация %d:\n", count);
		trystat();
	}

	return 0;
}

void trystat (void)
{
	int fade = 1;
	static int stay = 1;
	printf("fade = %d и stay = %d\n", fade++, stay++);
}