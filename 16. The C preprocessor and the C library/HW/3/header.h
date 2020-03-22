// заголовочный файл
#include<stdio.h>
#include<math.h>
#ifndef _header_h_
#define RAD_TO_DEG (180/(M_PI))

typedef struct {
	double magnitude;
	double angle;
}Pol_V;

typedef struct {
	double x;
	double y;
}Rect_V;

void poltorect (Pol_V *, Rect_V *);

inline static void eatline (void)
{
	while (getchar() != '\n')
		continue;
}
#endif
