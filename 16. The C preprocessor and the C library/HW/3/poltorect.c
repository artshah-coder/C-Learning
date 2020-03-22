// файл с главной функцией прграммы
#include"header.h"

int main (void)
{
	Rect_V coord_rect;
	Pol_V coord_pol;

	printf("Программа переводит полярные координаты в прямоугольные.\n");
	printf("Введите значения полярных координат в формате <модуль> <угол>(в градусах!)\n"
			"q - для выхода.\n");
	while (scanf("%lf%lf", &coord_pol.magnitude, &coord_pol.angle) == 2)
	{
		eatline();
		poltorect(&coord_pol, &coord_rect);
		printf("Прямоугольные координаты, соответствующие данным полярным: (%.2lf, %.2lf).\n", coord_rect.x, coord_rect.y);
		puts("Введите новую пару координат (или q для выхода):");
	}
	eatline();
	puts("Программа завершена!");

	return 0;
}

void poltorect (Pol_V * pol, Rect_V * rect)
{
	rect->x = pol->magnitude*cos(pol->angle/RAD_TO_DEG);
	rect->y = pol->magnitude*sin(pol->angle/RAD_TO_DEG);
}
