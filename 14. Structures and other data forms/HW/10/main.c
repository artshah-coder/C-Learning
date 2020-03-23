// main.c -- файл с главной функцией программы
#include"menu.h"

int main (void)
{
	void (*fp [CT]) (char * s);
	char * str = (char *) malloc(sizeof(char));
	char ch;
	printf("Программа-меню. Выполняет преобразование над строкой, введенной пользователем.\n");
	printf("Сначала введите строку, затем нажмите Enter\n");

	if (!get_str(str))
	{
		printf("Неизвестная ошибка при чтении вашего ввода.\n");
		exit(EXIT_FAILURE);
	}

	printf("Вы ввели: %s.\n", str);

	fp[0] = ToUpper;
       	fp[1] = ToLower;
	fp[2] = Change_Reg;
	fp[3] = invert_str;
	fp[4] = ct_smbls;

	printf("Теперь выберите функцию, которую хотите применить к вашей строке:\n"
			"a - Преобразовать в верхний регистр.\n"
			"b - Преобразовать в нижний регистр.\n"
			"c - Поменять регистры у входящих символов.\n"
			"d - Инвертировать строку.\n"
			"e - Вывести количество символов.\n"
			"f - Завершить работу программы.\n");
	while (tolower(ch = getchar()) && strchr("abcdef", ch) == NULL)
	{
		eatline();
		printf("Некорректный ввод. Введите одну из букв a-f\n");
	}
	eatline();

	while (ch != 'f')
	{
		switch(ch)
		{
			case 'a':
				fp[0](str);
				break;
			case 'b':
				fp[1](str);
				break;
			case 'c':
				fp[2](str);
				break;
			case 'd':
				fp[3](str);
				break;
			case 'e':
				fp[4](str);
				break;
		}
		printf("Теперь выберите функцию, которую хотите применить к вашей строке:\n"
				"a - Преобразовать в верхний регистр.\n"
				"b - Преобразовать в нижний регистр.\n"
				"c - Поменять регистры у входящих символов.\n"
				"d - Инвертировать строку.\n"
				"e - Вывести количество символов.\n"
				"f - Завершить работу программы\n");
		while (tolower(ch = getchar()) && strchr("abcdef", ch) == NULL)
		{
			eatline();
			printf("Некорректный ввод. Введите одну из букв a-f\n");
		}
		eatline();
	}

	free (str);
	puts("Программа завершена.");
	return 0;
}
