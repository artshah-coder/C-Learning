#include<stdio.h>
#include"insurance.h"

void prntstrct (INSR * insurance)
{
	char str[3];
	if (insurance->p.patronymic != NULL)
	{
		*str = *(insurance->p.patronymic);
		*(str + 1) = '.';
		*(str + 2) = '\0';
	}
	printf("%s, %s %s -- %d\n", insurance->p.surname, insurance->p.name,
			(insurance->p.patronymic != NULL ? str : ""), insurance->num);
}
