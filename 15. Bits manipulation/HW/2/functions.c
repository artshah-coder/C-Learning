#include"header.h"

unsigned int stob (char * str)					// конвертация строки в число
{
	if (str)						// в случае, если в функцию передан корректный указатель
	{
		unsigned int size = strlen(str);		// размер строки str
		unsigned int ret_val = str[size - 1] - '0';	// последняя цифра двоичной записи при переводе 2->10 входит в разложение с коэффициентом 1
		unsigned int mult;				// промежуточное произведение при переводе

		for (int i = 1; i < size; i++)
		{
			mult = str[size - i - 1] - '0';		// заносим значение слудующей  двоичной цифры в переменную mult
			if (mult == 0)				// если эта цифра 0, не имеет смысла считать коэффициент при ней,
				continue;			// на результат этот член влияния не окажет, переходим на следующую итерацию
			else
				for (int j = 1; j <= i; j++)	// в противном случае, формируем коэффициент при цифре 1 в цикле и заносим значение в переменную mult
					mult *= 2;		
			ret_val += mult;			// прибавляем полученное значение mult в переменную ret_val
		}
		return ret_val;
	}
	else
	{
		fprintf(stderr, "Указатель NULL в аргументе функции strtoint.\n");
		return -1;
	}
}

void btos (unsigned int n, char * str)				// конвертация числа в строку
{
	int size = CHAR_BIT*sizeof(unsigned int);

	for (int i = size - 1; i >= 0; i--, n >>= 1)
		str[i] = (n & 0x1) + '0';			// маскируем число на каждой итерации цикла. Прозрачный бит у маски - последний
	str[size] = '\0';
}
