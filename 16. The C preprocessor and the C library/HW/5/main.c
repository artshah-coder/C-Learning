#include"header.h"

int main (void)
{
	int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("Программа-драйвер для функции случайного выбора элементов массива.\n");
	printf("Исходный массив:\n");
	showarray(array, SIZE);
	printf("Выборка %d элементов из массива %d элементов:\n", SELECTIONS, SIZE);
	selection(array, SIZE, SELECTIONS);
	
	puts("Программа завершена!");

	return 0;
}
