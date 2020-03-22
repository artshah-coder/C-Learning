#include"header.h"

int main (void)
{
	int n;
	static int size = sizeof(unsigned int)*CHAR_BIT + 1;
	char str[size];
	printf("Введите целое число без знака:\n");
	while (scanf("%d", &n) != 1 || n < 0)
	{
		printf("Неверно. Попробуйте еще раз!\n"
				"Введите целое число без знака:\n");
		eatline();
	}
	btos(n, str);
	printf("%u в двоичном представлении: %s содержит %d включенных битов (-а).\n", n, str, bits(n));

	return 0;
}
