// diceroll.c -- файл с функциями для эмуляции игры в кости
#include<stdio.h>
#include<stdlib.h>
#include"diceroll.h"

static int rollem (int sides)
{
	return rand() % sides + 1;
}

int roll_n_dice (int dice, int sides)
{
	int total = 0;

	if (dice < 1)
	{
		printf("Необходима по меньшей мере 1 кость.\n");
		return -1;
	}
	if (sides < 2)
	{
		printf("У игральной кости должно быть по меньшей мере 2 стороны.\n");
		return -2;
	}

	for (int i = 0; i < dice; i++)
		total += rollem(sides);
	return total;
	
}
