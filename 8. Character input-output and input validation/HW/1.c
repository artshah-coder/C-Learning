// 1.c -- программа, подсчитывающая количество символов во входных данных до достижения конца файла
#include<stdio.h>


int main (void)
{
	unsigned int count = 0;
	printf("Программа подсчитывает количество символов во входных данных.\n");
	while (getchar() != EOF)
		count++;
	printf("\nИтого: %u символов\n", count);

	return 0;
}
