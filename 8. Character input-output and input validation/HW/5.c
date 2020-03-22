// 5.c -- программа по угадаванию загаданного пользователем числа (алгоритм улучшен по сравнению с примером из главы)
#include<stdio.h>
#include<ctype.h>
#define RAGE 100

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
	while ((ch = getchar()) != EOF)
	{
		while(isspace(ch))
			ch = getchar();
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
			case 'e':
				goto exit;
				break;
			default:
				printf("Некорректный ввод!\n");
				break;
		}
		printf("Ладно, тогда это %d?\n", guess);
	}
exit:	if (ch == 'e')
		printf("Я знал, что у меня получится!\n");
	printf("Программа завершена!\n");
	return 0;
}
