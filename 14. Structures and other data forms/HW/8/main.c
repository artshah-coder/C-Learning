#include"plane.h"

int main (void)
{
	PLACE ps [PLACES];
	FILE * fp;
	char ch;
	int number;
	int i, status;

	if ((fp = fopen("places.dat", "r+b")) == NULL)
	{
		fprintf(stderr, "Ошибка при открытии файла places.dat");
		exit(EXIT_FAILURE);
	}

	if (load_data(fp, ps, PLACES) == 0)
	{
		printf("В файле places.dat нет данных.\n");
		for (int i = 0; i < PLACES; i++)
		{
			ps[i].num = i + 1;
			ps[i].free = true;
			ps[i].name[0] = ps[i].surn[0] = '\0';
		}
	}

	printf("Программа-меню. Отображает свободные, забронированные "
			"места в самолете.\n"
			"Позволяет забронировать место, снять бронь с места.\n");
	printf("Для выбора функции введите ее буквенную метку:\n"
			"a) Показать количество свободных мест\n"
			"b) Показать список свободных мест\n"
			"c) Показать список забронированных мест в алфавитном порядке\n"
			"d) Забронировать место для пассажира\n"
			"e) Снять место с брони\n"
			"f) Выйти из программы\n");
	while (strchr("abcdef", (ch = getchar())) == NULL)
	{
		puts("Введите одну букву a-f:");
		eatline();
	}
	eatline();
	while (ch != 'f')
	{
		switch(ch)
		{
			case 'a':
				printf("Сейчас %d мест свободно.\n", ct_free(ps, PLACES));
				break;
			case 'b':
				for (i = 0; i < PLACES; i++)
					if (ps[i].free)
						break;
				if (i == PLACES)
					printf("Свободных мест нет.\n");
				else
				{
					printf("Свободные места:\n");
					ls_free(ps, PLACES);
				}
				break;
			case 'c':
				for (i = 0; i < PLACES; i++)
					if (!ps[i].free)
						break;
				if (i == PLACES)
					printf("Забронированных мест нет.\n");
				else
				{
					printf("Забронированные места:\n");
					ls_booked(ps, PLACES);
				}
				break;
			case 'd':
				for (i = 0; i < PLACES; i++)
					if (ps[i].free)
						break;
				if (i == PLACES)
					printf("Свободных мест нет.\n");
				else
				{
					printf("Введите номер свободного места.\n"
							"q - для выхода.\n");
					while ((status = scanf("%d", &number)) && number > 0 && number <= PLACES)
					{
						eatline();
						if (ps[number - 1].free)
						{
							printf("Введите фамилию пассажира.\n"
									"Enter в начале строки - для выхода.\n");
							if (s_gets(ps[number - 1].surn, STR) != NULL && ps[number - 1].surn[0] != '\0')
							{
								printf("Введите имя пассажира.\n"
										"Enter в начале строки - для выхода.\n");
								if (s_gets(ps[number - 1].name, STR) != NULL && ps[number - 1].name[0] != '\0')
								{
									book_place(ps, number - 1);
									printf("Готово! Место %d забронировано за пассажиром %s %s.\n",
											number, ps[number - 1].surn, ps[number - 1].name);
									break;
								}
								else
									break;
							}
							else
								break;
						}
						else
							printf("Место уже забронировано.\n"
									"Повторите ввод.\n");
					}
					if (number > PLACES || number < 1 || status == 0)
					{
						printf("Места с таким номером не существует.\n");
						eatline;
					}
				}
				break;
			case 'e':
				for (i = 0; i < PLACES; i++)
					if (ps[i].free == false)
						break;
				if (i == PLACES)
					printf("Все места свободны.\n");
				else
				{
					printf("Введите номер места, броню с которого вы хотите снять.\n"
							"q - для выхода.\n");
					while ((status = scanf("%d", &number)) && number > 0 && number <= PLACES)
					{
						eatline();
						if (ps[number - 1].free == false)
						{
							free_place(ps, number - 1);
							printf("Бронь с места %d снята.\n", number);
							break;
						}
						else
							printf("Место уже свободно. Нельзя снять бронь с не занятого места.\n"
									"Повторите ввод. Или нажмите q для выхода.\n");
					}
					if (number > PLACES || number < 1 || status == 0)
					{
						printf("Места с таким номером не существует.\n");
						eatline;
					}
				}
				break;
		}
		printf("Для выбора функции введите ее буквенную метку:\n"
				"a) Показать количество свободных мест\n"
				"b) Показать список свободных мест\n"
				"c) Показать список забронированных мест в алфавитном порядке\n"
				"d) Забронировать место для пассажира\n"
				"e) Снять место с брони\n"
				"f) Выйти из программы\n");
		while (strchr("abcdef", (ch = getchar())) == NULL)
		{
			puts("Введите одну из букв a-f:");
			eatline();
		}
		eatline();
	}
	
	if (writef(fp, ps, PLACES) == 0)
		printf("Ошибка записи в файл.\n");
	if (fclose(fp))
		printf("Ошибка при закрытии файла places.dat.\n");
	puts("Программа завершена!\n");
	return 0;
}
