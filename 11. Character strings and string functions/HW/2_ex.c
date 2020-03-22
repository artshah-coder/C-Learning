// 2_ex.c -- модифицированный вариант программы из 1_ex.c, упр. 2, стр. 477
#include<stdio.h>
#include<ctype.h>
#define SZ 6 // размер массива, в который извлекаются введенные символы

void extract_input (int n, char * arr); // извлекает из ввода следующие n символов и помещает их в массив arr

int main (void)
{
	char array [SZ];

	printf("Программа считывает из ввода %d латинских символов и извлекает их в array.\n"
			"Введите строку размером %d символов латинского алфавита:\n", SZ-1, SZ-1);
	extract_input(SZ, array);
	printf("array: %s", array);
	
	return 0;
}

void extract_input (int n, char * arr)
{
	int i = 0;
	while (i < n - 1)
	{
		*(arr + i) = getchar();
		if (isspace(*(arr + i)))
			break;
		i++;
	}
	*(arr + i) = '\0';
}
