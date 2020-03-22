// 10.c -- программа по переводу натурального числа из десятичной системы счисления в СС с основанием от 2 до 10
#include<stdio.h>

void to_base_n (long, short);
long get_nat_num (void);
short get_correct_base (void);

int main (void)
{
	long nat_num;
	short base;
	printf("Программа переводит введенное натуральное число из десятичной системы счисления\n"
			"в систему счисления с основанием от 2 до 10,\n"
			"которое также вводится с клавиатуры.\n");
	printf("Введите натуральное число в десятичнойсистеме счисления: ");
	nat_num = get_nat_num();
	printf("Отлично, теперь введите основание системы счисления от 2 до 10,\n"
			"в которую необходимо перевести введенное десятичное число: ");
	base = get_correct_base();
	printf("Введенное натуральное число в десятичной СС: %ld. Оно же в СС с основанием %hd: ", nat_num, base);
	to_base_n(nat_num, base);
	printf("\nПрограмма завершена!\n");
	
	return 0;
}

void to_base_n (long num, short base)
{
	unsigned long r;
	r = num % base;
	if ( num/base > 0)
		to_base_n (num/base, base);
	printf("%lu", r);
}

long get_nat_num (void)
{
	long input;
	while ( scanf("%ld", &input) != 1 || input <= 0)
	{
		while (getchar() != '\n')
			continue;
		printf("Некорректный ввод! Необходимо ввести натуральное число. Повторите: ");
	}
	
	return input;

}

short get_correct_base(void)
{
	short input;
	while (scanf("%hd", &input) != 1 || (input < 2 || input > 10))
	{
		while (getchar() != '\n')
			continue;
		printf("Некорректный ввод! Необходимо ввести основание системы счисление в диапазоне от 2 до 10.\n"
				"Повторите: ");
	}

	return input;
}
