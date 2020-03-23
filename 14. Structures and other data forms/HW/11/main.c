// файл с главной функцией
#include"header.h"

int main (void)
{
	double source [SZ], target [SZ];
	fill_arr(source, SZ);
	printf("Исходный массив:\n");
	prnt_arr(source, SZ);
	printf("\n\nЦелевой массив после передачи функции transform исходного массива и функции inverse:\n");
	transform(source, target, SZ, inverse);
	prnt_arr(target, SZ);
	printf("\n\nЦелевой массив после передачи функции transform исходного массива и функции square:\n");
	transform(source, target, SZ, square);
	prnt_arr(target, SZ);
	printf("\n\nЦелевой массив после передачи функции transform исходного массива и библиотечной функции cos:\n");
	transform(source, target, SZ, cos);
	prnt_arr(target, SZ);
	printf("\n\nЦелевой массив после передачи функции transform исходного массива и библиотечной функции sin:\n");
	transform(source, target, SZ, sin);
	prnt_arr(target, SZ);

	return 0;
}
