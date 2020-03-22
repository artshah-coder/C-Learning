#include"header.h"

unsigned int cshift (unsigned int val, unsigned int pos)
{
	static const int size = CHAR_BIT*sizeof(unsigned int);
	unsigned int mask = 1;			// переменная-маска для старших битов

	for (int i = 1; i < pos; i++)		// формируем маску для сдвигаемых битов
		mask =  (mask << 1) + 1;

	pos %= size;				// в pos имеет смысл сохранить остаток от деления исходного pos и количества битов, занимаемых типом unsigned int
	switch (pos)
	{
		case 0: 			// если pos 0 - сдвигемое число не изменяется, просто вернем переданное значение val
			return val; break;	
		default:			// в остальных случаях верем значение, полученное по формуле
			return (((val >> (size - pos)) & mask) + (val << pos)); break;

	}
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}
