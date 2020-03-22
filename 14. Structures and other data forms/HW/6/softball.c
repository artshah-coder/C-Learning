// здесь определены все функции, используемые в основной программе
#include"softball.h"
#include<stdio.h>

int eatline (FILE * f)			// функция очищает буфер потока от пробельных символов,
      					// которые игнориуются функцией fscanf()
					// принимает в качестве параметра файловый поток, возвращает целочисленный флаг,
					// достигнут конец файла (1) или нет (0)
{
	char ch;			// символ для хранения считанных из файла символов
	while ((ch = getc(f)) != '\n' && ch != EOF) // пока не наткнемся на символ перевода строки или EOF, читаем поток
		continue;
	
	if (ch == EOF) // если встретили EOF, возвращаем 1
		return 1;
	else if ((ch = getc(f)) == EOF) // если встретили символ '\n', но следующий за ним символ - символ EOF,
		return 1;		// возвращаем 1
	else				// если встретили символ '\n', но следующий за ним символ отличен от EOF
	{
		ungetc(ch, f);		// возвращаем считанный символ в поток
		return 0;		// из функции возвращаем 0
	}
}

void prnt_player_stats (PLAYER * p)		// вывод инфо о структуре PLAYER в stdout
{
	printf("%10s %10s %5d %5d %8d %5.2f\n", p->name, p->surname, p->points, p->runs, p->walks, p->BA);
}

void prnt_team_stats (PLAYER * p, int n)	// вывод инфо о команде (массива структур PLAYER) в stdout
{
	int runs = 0;
	int points = 0;
	int walks = 0;
	float BAs = 0.0;
	for (int i = 0; i < n; i++)
	{
		runs += (p + i)->runs;
		points += (p + i)->points;
		walks += (p + i)->walks;
		BAs += (p + i)->BA;
	}
	BAs /= n;
	
	printf("\nFull team's stats:\n"
			"%-18s %d\n"
			"%-18s %d\n"
			"%-18s %d\n"
			"%-18s %.2f\n",
			"Runs:", runs, "Points:", points, "Walks:", walks, "BAs:", BAs);
}
