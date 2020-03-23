// здесь располагаются все функции, необходимые для работы основной программы
#include<stdio.h>
#include<string.h>
#include"manybooks.h"

char * s_gets (char * st, int n)
{
	char * ret_val;
	char * find;
	if ((ret_val = fgets(st, n, stdin)))	// считываем строку из stdin в массив st размерности n
		if ((find = strchr(st, '\n')))	// в случае успеха, пытаемся найти символ новой строки
			*find = '\0';		// в случае успеха, заменяем этот символ нулевым символом
		else
			eatline();		// если перенос строки не найден в массиве st размерности n,
						// очищаем буфер stdin
	return ret_val;
}

void eatline (void)
{
	while (getchar() != '\n')		// читаем поток ввода, пока не встречен символ новой строки,
		continue;
}

void fltsrt (BOOK * library, int n)
{
	BOOK temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((library + i)->value > (library + j)->value)
			{
				temp = *(library + i);
				*(library + i) = *(library + j);
				*(library + j) = temp;
			}
}

void alphsrt (BOOK * library, int n)
{
	BOOK temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp((library + i)->title, (library + j)->title) > 0)
			{
				temp = *(library + i);
				*(library + i) = *(library + j);
				*(library + j) = temp;
			}
}
