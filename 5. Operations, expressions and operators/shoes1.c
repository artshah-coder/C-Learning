#include<stdio.h>
#define ADJUST 7.31

int main(void)
{
	const double SCALE = 0.333;
	double shoe, foot;

	shoe = 9.0;
	foot = SCALE*shoe+ADJUST;
	printf("Размер обуви (мужской)	длина ступни\n");
	printf("%10.1f %20.2f дюймов\n", shoe, foot);

	return 0;
}
