#include"header.h"

int main (void)
{
	struct names ar[COUNT] = {{"Artyom", "Shahalov"}, {"Alexey", "Lazarev"}, {"Dmitriy", "Glebenkov"}, {"Maxim", "Kulakovskiy"}};
	puts("Исходный массив:");
	showarray(ar, COUNT);
	qsort(ar, COUNT, sizeof(struct names), mycomp);
	puts("\nОтсортированный массив:");
	showarray(ar, COUNT);
	puts("Программа завершена!");

	return 0;
}
