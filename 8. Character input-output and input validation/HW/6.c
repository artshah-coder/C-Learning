// 6.c -- модификация функции get_first(), возвращающей первый непробельный символ, более изящный вариант программы из упражнения 5
#include<stdio.h>
#include<ctype.h>
#define RAGE 100

char get_first (void);

int main (void)
{
	char ch;
	unsigned int down_border = 1; // нижняя граница диапазона, в котором лежит угадываемое значение
	unsigned int up_border = RAGE; // верхняя граница диапазона, в котором лежит указываемое значение
	unsigned int guess = (up_border + down_border)/2; // переменная, хранящая гипотетическое значние загаданного числа
	
	printf("Загадайте натуральное число в диапазоне от 1 до %u. Я попробую его угадать "
			"его. Нажмите клавишу l, если моя догадка больше загаданного числа;\n"
			"клавишу m, если меньше;\n"
			"наконец, клавишу e в случае, если я угадал :)\n");
	printf("Вашим числом является %u?\n", guess);
	while ((ch = get_first()) != EOF && ch != 'e')
	{
		switch (ch)
		{
			case 'l':
				up_border = guess;
				guess = (down_border + up_border)/2;
				break;
			case 'm':
				down_border = guess;
				guess = (down_border + up_border)/2;
				break;
			default:
				printf("Некорректный ввод!\n");
				break;
		}
		printf("Это %d?\n", guess);
	}
	if (ch == 'e')
		printf("Я знал, что у меня получится!\n");
	printf("Программа завершена!\n");
	
	return 0;
}

char get_first(void)
{
	char ch;
	while (isspace(ch = getchar()))
		continue;
	return ch;
}
