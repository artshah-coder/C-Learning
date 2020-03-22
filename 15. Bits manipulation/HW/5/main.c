#include"header.h"

int main (void)
{
	unsigned int val, shift;				// переменная для хранения числа и сдвига
	printf("Программа-драйвер для функции циклического сдвига влево.\n");
	printf("Задайте беззнаковое целое число:\n");
	while (scanf("%u", &val) != 1 || val < 0)
	{
		printf("Ошибочный ввод!\n"
				"Введите целое число без знака:\n");
		eatline();
	}

	printf("Теперь задайте неотрицательную величину циклического сдвига влево для вашего числа.\n");
	while (scanf("%u", &shift) != 1 || shift < 0)
	{
		printf("Ошибочный ввод!\n"
				"Задайте корректное значение:\n");
		eatline();
	}
	printf("cshift(%u, %u) = %u.\n", val, shift, cshift(val, shift));
	puts("Программа завершена!");

	return 0;
}
