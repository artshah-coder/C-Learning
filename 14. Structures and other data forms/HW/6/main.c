// здесь содержится главная функция
#include<stdio.h>
#include<stdlib.h>
#include"softball.h"

int main (void)
{
	PLAYER team [PLAYERS];		// массив структур PLAYER
	FILE * fp;
	int eof = 0;			// переменная-флаг для индикации конца файла
					// 1 - конец файла достигнут, 0 - в противном случае
	int number;			// переменная для хранения порядкового номера игрока (индекс массива)
	int iread;			// переменная, куда читаются целые значения из файла (кроме номера игрока)
	float fread;			// переменная, куда читаются вещественные значения из файла
	BA bas [PLAYERS];		// массив средних достижений игроков
					// (отношение числа ударов к числу выходов на ударные позиции)
	
	if ((fp = fopen(INPUT_FILE, "r")) == NULL)	// открытие на чтение файла со статистикой игроков
	{
		fprintf(stderr, "Не удается открыть файл %s на чтение.\n", INPUT_FILE);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < PLAYERS; i++)
		bas[i].hit_pos = bas[i].hits = team[i].points = team[i].runs = team[i].walks = 0;

	while (!eof)
	{
		fscanf(fp, "%d", &number);
		if (number > PLAYERS || number < 1)
		{
			fprintf(stderr, "В файле %s обнаружен некорректный номер игрока.\n"
					"Для простоты, номера игроков должны быть порядковыми, в диапазоне 1-%d,"
					" но не игровыми.\n"
					"Поправьте данные во входном файле и перезапустите программу.\n",
					INPUT_FILE, PLAYERS);
			exit(EXIT_FAILURE);
		}
		
		fscanf(fp, "%s", team[number - 1].name);
		fscanf(fp, "%s", team[number - 1].surname);
		
		fscanf(fp, "%d", &iread);
		if (iread < 0)
		{
			fprintf(stderr, "В файле %s обнаружены некорректные данные.\n"
					"Статистические показатели игроков не могут быть отрицательными.\n"
					"В частности, у игрока %s %s с номером %d число выходов "
					"на ударную позицию отрицательно.\n"
					"Поправьте данные во входном файле и перезапустите программу.\n",
					INPUT_FILE, team[number - 1].name, team[number - 1].surname, number);
			exit(EXIT_FAILURE);
		}
		
		bas[number - 1].hit_pos += iread;

		fscanf(fp, "%d", &iread);
		if (iread < 0)
		{
			fprintf(stderr, "В файле %s обнаружены некорректные данные.\n"
					"Статистические показатели игроков не могут быть отрицательными.\n"
					"В частности, у игрока %s %s с номером %d число ударов отрицательно.\n"
					"Поправьте данные во входном файле и перезапустите программу.\n",
					INPUT_FILE, team[number - 1].name, team[number - 1].surname, number);
			exit(EXIT_FAILURE);
		}
		
		bas[number - 1].hits += iread;

		fscanf(fp, "%d", &iread);
		if (iread < 0)
		{
			fprintf(stderr, "В файле %s обнаружены некорректные данные.\n"
					"Статистические показатели игроков не могут быть отрицательными.\n"
					"В частности, у игрока %s %s с номером %d число проходов отрицательно.\n"
					"Поправьте данные во входном файле и перезапустите программу.\n",
					INPUT_FILE, team[number - 1].name, team[number - 1].surname, number);
			exit(EXIT_FAILURE);
		}

		team[number - 1].walks += iread;

		fscanf(fp, "%d", &iread);
		if (iread < 0)
		{
			fprintf(stderr, "В файле %s обнаружены некорректные данные.\n"
					"Статистические показатели игроков не могут быть отрицательными.\n"
					"В частности, у игрока %s %s с номером %d число засчитанных пробежек "
					"отрицательно.\n"
					"Поправьте данные во входном файле и перезапустите программу.\n",
					INPUT_FILE, team[number - 1].name, team[number - 1].surname, number);
			exit(EXIT_FAILURE);
		}

		team[number - 1].runs += iread;
		team[number - 1].points = team[number - 1].runs;
		eof = eatline(fp);
	}

	for (int i = 0; i < number; i++)
		if (bas[i].hit_pos != 0)
			if (bas[i].hit_pos >= bas[i].hits)
				team[i].BA = (float) bas[i].hits/bas[i].hit_pos;
			else
			{
				fprintf(stderr, "В файле %s обнаружены некорректные данные.\n"
						"У игрока %s %s с номером %d "
						"число ударов больше числа выходов на ударную позицию.\n"
						"Это исключено.\nПоправьте данные во входном файле и "
						"перезапустите программу.\n",
						INPUT_FILE, team[i].name, team[i].surname, i + 1);
				exit(EXIT_FAILURE);
			}
		else
			if (bas[i].hits != 0)
			{
				fprintf(stderr, "В файле %s обнаружены некорректные данные.\n"
						"У игрока %s %s с номером %d "
						"выходов на ударную позицию 0, ударов: %d.\n"
						"Это исключено.\nПоправьте данные во входном файле и "
						"перезапустите программу.\n",
						INPUT_FILE, team[i].name, team[i].surname, i + 1, bas[i].hits);
				exit(EXIT_FAILURE);
			}
	printf("Players stats:\n");
	printf("%10s %10s %5s %5s %8s %5s\n", "Name", "Surname", "Points", "Runs", "Walks", "BA");
	for (int i = 0; i < number; i++)
		prnt_player_stats(team + i);
	prnt_team_stats(team, number);

	if (fclose(fp))
		fprintf(stderr, "Ошибка при закрытии файла %s.", INPUT_FILE);

	return 0;
}
