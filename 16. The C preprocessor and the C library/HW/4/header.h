#include<stdio.h>
#include<time.h>
#include<math.h>
#ifndef _header_h_
inline static void eatline (void)	// встроенная функция, удаляющая лишние символы из ввода
{
	while (getchar() != '\n')
		continue;
}

void delay_sec (double);		// прототип функции задержки по времени
#endif
