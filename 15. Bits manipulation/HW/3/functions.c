// объявление всех функций, используемых в программе
#include"header.h"

int bits (unsigned int n)		// подсчет включенных битов в числе
{
	int count = 0;
	do
	{
		if (n & 0x1)		// проверяем последовательно все биты числа, начиная с конца
			count++;	// в случае, если бит включен, увеличиваем счетчик
	
	}
	while (n >>= 1);

	return count;
}

void eatline (void)			// функция очистки буфера от лишних символов
{
	while (getchar() != '\n')	// пока не встретим символ новой строки, читать лишние символы без сохранения
		continue;
}

void btos (int n, char * s)		// конвертация числа в строку
{
	static const int size = sizeof(unsigned int)*CHAR_BIT;
	for (int i = size - 1; i >= 0; i--, n >>= 1)
		s[i] = (n & 0x1) + '0';
	s[size] = '\0';
}
