#include<stdio.h>
#include<string.h>
#include<ctype.h>	// для tolower()

void eatline (void)	// считывает оставшиеся символы в буфере, вплоть до символа новой строки
{
	while (getchar() != '\n')
		continue;
}

char * ToLower (char * st)
{
	int i = 0;
	while (*st)
	{
		*st = tolower(*st);
		st++;
		i++;
	}
	
	return (st - i); 
}

