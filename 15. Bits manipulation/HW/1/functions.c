#include"header.h"

unsigned int strtoint (char * str)
{
	if (str)
	{
		unsigned int size = strlen(str);
		unsigned int ret_val = str[size - 1] - '0';
		unsigned int mult;

		for (int i = 1; i < size; i++)
		{
			mult = str[size - i - 1] - '0';
			if (mult == 0)
			{
				ret_val += mult;
				continue;
			}
			else
				for (int j = 1; j <= i; j++)
					mult *= 2;
			ret_val += mult;
		}
		return ret_val;
	}
	else
	{
		fprintf(stderr, "Указатель NULL в аргументе функции strtoint.\n");
		return -1;
	}
}
