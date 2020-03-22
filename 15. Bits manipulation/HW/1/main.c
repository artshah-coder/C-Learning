#include"header.h"

int main (void)
{
	char * str = "101000111";
	printf("Программа преобразует двоичную строку в беззнаковое целое.\n");
	printf("Строка %s преобразуется в число %u.\n", str, strtoint(str));
	puts("Программа завершена!");

	return 0;
}
