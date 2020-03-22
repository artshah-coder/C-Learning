/* comp_quest.c -- файл с функциями, реализующими "загаданное" компьютером число */
#include<stdlib.h>
#include<time.h>
#include"comp_quest.h"

int comp_quest (void)
{
	srand ((unsigned int) time (NULL));
	return rand() % MAX + 1;	
}
