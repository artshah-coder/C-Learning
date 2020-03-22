#include"header.h"

int main (void)
{
	int n, bit;
	static const int size = sizeof(unsigned int)*CHAR_BIT + 1;
	char str[size];
	printf("Программа проверяет, включен ли указанный бит во введенном числе:\n");
	printf("Введите целое число без знака, которое вы хотите исследовать:\n");
	while (scanf("%d", &n) != 1 || n < 0)
	{
		printf("Ошибка!\nВведите целое число без знака:\n");
		eatline();
	}
	printf("Теперь введите номер бита из диапазона 1-%d, который вы хотите проверить:\n", (int) CHAR_BIT*sizeof(unsigned int));
	while (scanf("%d", &bit) != 1 || n < 1 || n > CHAR_BIT*sizeof(unsigned int))
	{
		printf("Ошибка!\nВведите число из диапазона 1-%d.\n", (int) CHAR_BIT*sizeof(unsigned int));
		eatline();
	}
	btos(n, str);
	printf("Число %d представляется как %s.\n", n, str);
	if (onbit(n, bit))
		printf("Бит %d в числе %d включен.\n", bit, n);
	else
		printf("Бит %d в числе %d выключен.\n", bit, n);
	puts("Программа завершена!");


	return 0;
}
