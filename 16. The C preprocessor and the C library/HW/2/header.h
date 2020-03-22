// заголовочный файл
#include<stdio.h>
#ifndef _header_h_
#define HARMAVG(X, Y) ( 1 / ( (1 / ((double) (X)) + 1 / ((double) (Y)) ) / 2 ) ) 
inline void static eatline(void)
{
	while(getchar() != '\n')
		continue;
}
#endif
