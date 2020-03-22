// функции программы
#include"header.h"

int onbit (int n, int bit)
{
	for (int i = 1; i < bit; i++)
		n >>= 1;
	if (n & 0x1)
		return 1;
	else
		return 0;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

void btos (int n, char * str)
{
	static const int size = CHAR_BIT*sizeof(unsigned int);
	for (int i = size - 1; i >= 0; i--, n >>= 1)
		str[i] = (n & 0x1) + '0';
	str[size] = '\0';
}
