// 13.c -- программа инверсного вывода аргументов командной строки
#include<stdio.h>

int main (int argc, char * argv[])
{
	int i;
	puts("Вывод аргументов командной строки в обратном порядке:");
	for (i = argc - 1; i > 0; i--)
		puts(*(argv + i));
	
	return 0;
}
