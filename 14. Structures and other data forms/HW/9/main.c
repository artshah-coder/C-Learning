#include"plane.h"

int main (void)
{
	PLACE ps [FLIGHTS][PLACES];
	FILE * fp;
	char ch;
	int number;
	int i, status;

	if ((fp = fopen("places.dat", "r+b")) == NULL)
	{
		fprintf(stderr, "Ошибка при открытии файла places.dat");
		exit(EXIT_FAILURE);
	}

	if (load_data(fp, *ps, FLIGHTS*PLACES) == 0)
	{
		printf("В файле places.dat нет данных.\n");
		for (int i = 0; i < FLIGHTS; i++)
			for (int j = 0; j < PLACES; j++)
		{
			(*(ps + i) + j)->num = j + 1;
			(*(ps + i) + j)->free = true;
			(*(ps + i) + j)->name[0] = (*ps + i)->surn[0] = '\0';
		}
	}

	printf("Программа-меню. Реализован выбор рейса,\n"
			"отображение свободных, забронированных "
			"мест в самолете.\n"
			"Позволяет забронировать место, снять бронь с места.\n");
	printf("Сначала выберете рейс:\n"
			"1 - 102	2 - 311\n"
			"3 - 444	4 - 519\n"
			"5 - завершить программу.\n");
	while (strchr("12345", (ch = getchar())) == NULL)
	{
		puts("Введите цифру из диапазона 1-5:");
		eatline();
	}
	eatline();

	while (ch != '5')
	{
		switch (ch)
		{
			case '1':
				printf("ВЫБРАН РЕЙС 102.\n"
						"Для выбора функции введите ее буквенную метку:\n"
						"a) Показать количество свободных мест\n"
						"b) Показать список свободных мест\n"
						"c) Показать список забронированных мест в алфавитном порядке\n"
						"d) Забронировать место для пассажира\n"
						"e) Подтвердить бронь места\n"
						"f) Снять бронь с места\n"
						"g) Перейти к выбору рейса.\n");
				while (strchr("abcdefg", (ch = getchar())) == NULL)
				{
					puts("Введите букву из диапазона a-g");
					eatline();
				}
				eatline();
				
				while (ch != 'g')
				{
					switch(ch)
					{
						case 'a':
							printf("Сейчас %d мест свободно.\n", ct_free(*ps, PLACES));
							break;
						case 'b':
							for (i = 0; i < PLACES; i++)
								if ((*ps + i)->free)
									break;
							if (i == PLACES)
								printf("Свободных мест нет.\n");
							else
							{
								printf("Свободные места:\n");
								ls_free(*ps, PLACES);
							}
							break;
						case 'c':
							for (i = 0; i < PLACES; i++)
								if (!(*ps + i)->free)
									break;
							if (i == PLACES)
								printf("Забронированных мест нет.\n");
							else
							{
								printf("Забронированные места:\n");
								ls_booked(*ps, PLACES);
							}
							break;
						case 'd':
							for (i = 0; i < PLACES; i++)
								if ((*ps + i)->free)
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
									if ((*ps + number - 1)->free)
									{
										printf("Введите фамилию пассажира.\n"
												"Enter в начале строки - для выхода.\n");
										if (s_gets((*ps + number - 1)->surn, STR) != NULL && (*ps + number - 1)->surn[0] != '\0')
										{
											printf("Введите имя пассажира.\n"
												"Enter в начале строки - для выхода.\n");
											if (s_gets((*ps + number - 1)->name, STR) != NULL && (*ps + number - 1)->name[0] != '\0')
											{
												printf("Оформлена предварительная бронь на место %d за пассажиром %s %s.\n"
														"Для подтверждения брони, выберете соответствующий пункт меню.\n",
														number, (*ps + number - 1)->surn, (*ps + number - 1)->name);
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
								if ((*ps + i)->free && (*ps + i)->surn[0] != '\0')
									break;
							if (i == PLACES)
								printf("Нет мест, ожидающих подтверждения брони.\n");
							else
							{
								printf("Введите номер места, бронь которого вы хотите подтвердить.\n"
										"q - для выхода.\n");
								while ((status = scanf("%d", &number)) && number > 0 && number <= PLACES)
								{
									eatline();
									if ((*ps + number - 1)->free && (*ps + number - 1)->surn[0] != '0')
									{
										book_place(*ps + number - 1);
										printf("Место %d забронировано за %s %s.\n", number, (*ps + number - 1)->surn, (*ps + number - 1)->name);
										break;
									}
									else if ((*ps + number - 1)->free == false)
										printf("Место было забронировано ранее. Повторите ввод.\n");
									else
										printf("Не было оформлено предварительной брони на это место.\n"
												"Повторите ввод.\n");
								}
								if (number > PLACES || number < 1 || status == 0)
								{
									printf("Места с таким номером не существует.\n");
									eatline();
								}
							}
							break;
						case 'f':
							for (i = 0; i < PLACES; i++)
								if ((*ps + i)->free == false)
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
									if ((*ps + number - 1)->free == false)
									{
										free_place(*ps + number - 1);
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
					printf("ВЫБРАН РЕЙС 102.\n"
							"Для выбора функции введите ее буквенную метку:\n"
							"a) Показать количество свободных мест\n"
							"b) Показать список свободных мест\n"
							"c) Показать список забронированных мест в алфавитном порядке\n"
							"d) Забронировать место для пассажира\n"
							"e) Подтвердить бронь места\n"
							"f) Снять бронь с места\n"
							"g) Перейти к выбору рейса.\n");
					while (strchr("abcdefg", (ch = getchar())) == NULL)
					{
						puts("Введите букву из диапазона a-g");
						eatline();
					}
					eatline();
				}
				break;
			case '2':
				printf("ВЫБРАН РЕЙС 311.\n"
						"Для выбора функции введите ее буквенную метку:\n"
						"a) Показать количество свободных мест\n"
						"b) Показать список свободных мест\n"
						"c) Показать список забронированных мест в алфавитном порядке\n"
						"d) Забронировать место для пассажира\n"
						"e) Подтвердить бронь места\n"
						"f) Снять бронь с места\n"
						"g) Перейти к выбору рейса.\n");
				while (strchr("abcdefg", (ch = getchar())) == NULL)
				{
					puts("Введите букву из диапазона a-g");
					eatline();
				}
				eatline();
				while (ch != 'g')
				{
				switch(ch)
				{
					case 'a':
						printf("Сейчас %d мест свободно.\n", ct_free(*(ps + 1), PLACES));
						break;
					case 'b':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 1) + i)->free)
								break;
						if (i == PLACES)
							printf("Свободных мест нет.\n");
						else
						{
							printf("Свободные места:\n");
							ls_free(*(ps + 1), PLACES);
						}
						break;
					case 'c':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 1) + i)->free == false)
								break;
						if (i == PLACES)
							printf("Забронированных мест нет.\n");
						else
						{
							printf("Забронированные места:\n");
							ls_booked(*(ps + 1), PLACES);
						}
						break;
					case 'd':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 1) + i)->free)
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
								if ((*(ps + 1) + number - 1)->free)
								{
									printf("Введите фамилию пассажира.\n"
											"Enter в начале строки - для выхода.\n");
									if (s_gets((*(ps + 1) + number - 1)->surn, STR) != NULL && (*(ps + 1) + number - 1)->surn[0] != '\0')
									{
										printf("Введите имя пассажира.\n"
												"Enter в начале строки - для выхода.\n");
										if (s_gets((*(ps + 1) + number - 1)->name, STR) != NULL && (*(ps + 1) + number - 1)->name[0] != '\0')
										{
											printf("Оформлена предварительная бронь на место %d за пассажиром %s %s.\n",
													number, (*(ps + 1) + number - 1)->surn, (*(ps + 1) + number - 1)->name);
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
								eatline();
							}
						}
						break;
					case 'e':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 1) + i)->free && (*(ps + 1) + i)->surn[0] != '\0')
								break;
						if (i == PLACES)
							printf("Нет мест, ожидающих подтверждения брони.\n");
						else
						{
							printf("Введите номер места, бронь которого вы хотите подтвердить.\n"
									"q - для выхода.\n");
							while ((status = scanf("%d", &number)) && number > 0 && number <= PLACES)
							{
								eatline();
								if ((*(ps + 1) + number - 1)->free && (*(ps + 1) + number - 1)->surn[0] != '0')
								{
									book_place(*(ps + 1) + number - 1);
									printf("Место %d забронировано за %s %s.\n", number, (*(ps + 1) + number - 1)->surn, (*(ps + 1) + number - 1)->name);
									break;
								}
								else if ((*(ps + 1) + number - 1)->free == false)
									printf("Место было забронировано ранее. Повторите ввод.\n");
								else
									printf("На это место не было оформлено предварительной брони на место.\n"
											"Повторите ввод.\n");
							}
							if (number > PLACES || number < 1 || status == 0)
							{
								printf("Места с таким номером не существует.\n");
								eatline();
							}
						}
						break;
					case 'f':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 1) + i)->free == false)
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
								if ((*(ps + 1) + number - 1)->free == false)
								{
									free_place(*(ps + 1) + number - 1);
									printf("Бронь с места %d снята.\n", number);
									break;
								}
								else
									printf("Место свободно. Нельзя снять бронь с не занятого места.\n"
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
				printf("ВЫБРАН РЕЙС 311.\n"
						"Для выбора функции введите ее буквенную метку:\n"
						"a) Показать количество свободных мест\n"
						"b) Показать список свободных мест\n"
						"c) Показать список забронированных мест в алфавитном порядке\n"
						"d) Забронировать место для пассажира\n"
						"e) Подтвердить бронь места\n"
						"f) Снять бронь с места\n"
						"g) Перейти к выбору рейса.\n");
				while (strchr("abcdefg", (ch = getchar())) == NULL)
				{
					puts("Введите букву из диапазона a-g");
					eatline();
				}
				eatline();
				}
				break;
			case '3':
				printf("ВЫБРАН РЕЙС 444.\n"
						"Для выбора функции введите ее буквенную метку:\n"
						"a) Показать количество свободных мест\n"
						"b) Показать список свободных мест\n"
						"c) Показать список забронированных мест в алфавитном порядке\n"
						"d) Забронировать место для пассажира\n"
						"e) Подтвердить бронь места\n"
						"f) Снять бронь с места\n"
						"g) Перейти к выбору рейса.\n");
				while (strchr("abcdefg", (ch = getchar())) == NULL)
				{
					puts("Введите букву из диапазона a-g");
					eatline();
				}
				eatline();
				switch(ch)
				{
					case 'a':
						printf("Сейчас %d мест свободно.\n", ct_free(*(ps + 2), PLACES));
						break;
					case 'b':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 2) + i)->free)
								break;
						if (i == PLACES)
							printf("Свободных мест нет.\n");
						else
						{
							printf("Свободные места:\n");
							ls_free(*(ps + 2), PLACES);
						}
						break;
					case 'c':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 2) + i)->free == false)
								break;
						if (i == PLACES)
							printf("Забронированных мест нет.\n");
						else
						{
							printf("Забронированные места:\n");
							ls_booked(*(ps + 2), PLACES);
						}
						break;
					case 'd':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 2) + i)->free)
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
								if ((*(ps + 2) + number - 1)->free)
								{
									printf("Введите фамилию пассажира.\n"
											"Enter в начале строки - для выхода.\n");
									if (s_gets((*(ps + 2) + number - 1)->surn, STR) != NULL && (*(ps + 2) + number - 1)->surn[0] != '\0')
									{
										printf("Введите имя пассажира.\n"
												"Enter в начале строки - для выхода.\n");
										if (s_gets((*(ps + 2) + number - 1)->name, STR) != NULL && (*(ps + 2) + number - 1)->name[0] != '\0')
										{
											printf("Оформлена предварительная бронь на место %d за пассажиром %s %s.\n",
													number, (*(ps + 2) + number - 1)->surn, (*(ps + 2) + number - 1)->name);
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
							if ((*(ps + 2) + i)->free && (*(ps + 2) + i)->surn[0] != '\0')
								break;
						if (i == PLACES)
							printf("Нет мест, ожидающих подтверждения брони.\n");
						else
						{
							printf("Введите номер места, бронь которого вы хотите подтвердить.\n"
									"q - для выхода.\n");
							while ((status = scanf("%d", &number)) && number > 0 && number <= PLACES)
							{
								eatline();
								if ((*(ps + 2) + number - 1)->free && (*(ps + 2) + number - 1)->surn[0] != '0')
								{
									book_place(*(ps + 2) + number - 1);
									printf("Место %d забронировано за %s %s.\n", number, (*(ps + 2) + number - 1)->surn, (*(ps + 2) + number - 1)->name);
									break;
								}
								else if ((*(ps + 2) + number - 1)->free == false)
									printf("Место было забронировано ранее. Повторите ввод.\n");
								else
									printf("На это место не было оформлено предварительной брони на место.\n"
											"Повторите ввод.\n");
							}
							if (number > PLACES || number < 1 || status == 0)
							{
								printf("Места с таким номером не существует.\n");
								eatline();
							}
						}
						break;
					case 'f':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 2) + i)->free == false)
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
								if ((*(ps + 2) + number - 1)->free == false)
								{
									free_place(*(ps + 2) + number - 1);
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
				printf("ВЫБРАН РЕЙС 444.\n"
						"Для выбора функции введите ее буквенную метку:\n"
						"a) Показать количество свободных мест\n"
						"b) Показать список свободных мест\n"
						"c) Показать список забронированных мест в алфавитном порядке\n"
						"d) Забронировать место для пассажира\n"
						"e) Подтвердить бронь места\n"
						"f) Снять бронь с места\n"
						"g) Перейти к выбору рейса.\n");
				while (strchr("abcdefg", (ch = getchar())) == NULL)
				{
					puts("Введите букву из диапазона a-g");
					eatline();
				}
				eatline();
				break;
			case '4':
				printf("ВЫБРАН РЕЙС 519.\n"
						"Для выбора функции введите ее буквенную метку:\n"
						"a) Показать количество свободных мест\n"
						"b) Показать список свободных мест\n"
						"c) Показать список забронированных мест в алфавитном порядке\n"
						"d) Забронировать место для пассажира\n"
						"e) Подтвердить бронь места\n"
						"f) Снять бронь с места\n"
						"g) Перейти к выбору рейса.\n");
				while (strchr("abcdefg", (ch = getchar())) == NULL)
				{
					puts("Введите букву из диапазона a-g");
					eatline();
				}
				eatline();
				switch(ch)
				{
					case 'a':
						printf("Сейчас %d мест свободно.\n", ct_free(*(ps + 3), PLACES));
						break;
					case 'b':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 3) + i)->free)
								break;
						if (i == PLACES)
							printf("Свободных мест нет.\n");
						else
						{
							printf("Свободные места:\n");
							ls_free(*(ps + 3), PLACES);
						}
						break;
					case 'c':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 3) + i)->free == false)
								break;
						if (i == PLACES)
							printf("Забронированных мест нет.\n");
						else
						{
							printf("Забронированные места:\n");
							ls_booked(*(ps + 3), PLACES);
						}
						break;
					case 'd':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 3) + i)->free)
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
								if ((*(ps + 3) + number - 1)->free)
								{
									printf("Введите фамилию пассажира.\n"
											"Enter в начале строки - для выхода.\n");
									if (s_gets((*(ps + 3) + number - 1)->surn, STR) != NULL && (*(ps + 3) + number - 1)->surn[0] != '\0')
									{
										printf("Введите имя пассажира.\n"
												"Enter в начале строки - для выхода.\n");
										if (s_gets((*(ps + 3) + number - 1)->name, STR) != NULL && (*(ps + 3) + number - 1)->name[0] != '\0')
										{
											printf("Оформлена предварительная бронь на место  %d за пассажиром %s %s.\n",
													number, (*(ps + 3) + number - 1)->surn, (*(ps + 3) + number - 1)->name);
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
							if ((*(ps + 3) + i)->free && (*(ps + 3) + i)->surn[0] != '\0')
								break;
						if (i == PLACES)
							printf("Нет мест, ожидающих подтверждения брони.\n");
						else
						{
							printf("Введите номер места, бронь которого вы хотите подтвердить.\n"
									"q - для выхода.\n");
							while ((status = scanf("%d", &number)) && number > 0 && number <= PLACES)
							{
								eatline();
								if ((*(ps + 3) + number - 1)->free && (*(ps + 3) + number - 1)->surn[0] != '0')
								{
									book_place(*(ps + 3) + number - 1);
									printf("Место %d забронировано за %s %s.\n", number, (*(ps + 3) + number - 1)->surn, (*(ps + 3) + number - 1)->name);
									break;
								}
								else if ((*(ps + 3) + number - 1)->free == false)
									printf("Место было забронировано ранее. Повторите ввод.\n");
								else
									printf("На это место не было оформлено предварительной брони на место.\n"
											"Повторите ввод.\n");
							}
							if (number > PLACES || number < 1 || status == 0)
							{
								printf("Места с таким номером не существует.\n");
								eatline();
							}
						}
						break;
					case 'f':
						for (i = 0; i < PLACES; i++)
							if ((*(ps + 3) + i)->free == false)
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
								if ((*(ps + 3) + number - 1)->free == false)
								{
									free_place(*(ps + 3) + number - 1);
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
				printf("ВЫБРАН РЕЙС 519.\n"
						"Для выбора функции введите ее буквенную метку:\n"
						"a) Показать количество свободных мест\n"
						"b) Показать список свободных мест\n"
						"c) Показать список забронированных мест в алфавитном порядке\n"
						"d) Забронировать место для пассажира\n"
						"e) Подтвердить бронь места\n"
						"f) Снять бронь с места\n"
						"g) Перейти к выбору рейса.\n");
				while (strchr("abcdefg", (ch = getchar())) == NULL)
				{
					puts("Введите букву из диапазона a-g");
					eatline();
				}
				eatline();
				break;
				
		}
		printf("Сначала выберете рейс:\n"
			"1 - 102        2 - 311\n"
			"3 - 444        4 - 519\n"
			"5 - завершить программу.\n");
		while (strchr("12345", (ch = getchar())) == NULL)
		{
			puts("Введите цифру из диапазона 1-5:");
			eatline();
		}
		eatline();
	}

	if (writef(fp, *ps, FLIGHTS*PLACES) == 0)
		printf("Ошибка записи в файл.\n");

	if (fclose(fp))
		printf("Ошибка при закрытии файла places.dat.\n");

	puts("Программа завершена!\n");

	return 0;
}
