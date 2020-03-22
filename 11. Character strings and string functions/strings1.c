// strings1.c
#include<stdio.h>
#include<locale.h>
#define MSG "я - старомодна€ символьна€ строкова€ константа."
#define MAXLENGTH 81

int main (void)
{
	char words [MAXLENGTH] = "я €вл€юсь строкой, хран€щейс€ в массиве.";
	const char * pt1 = "„то-то указывает на мен€.";
	setlocale (LC_ALL, "Rus");
	puts ("¬от несколько строк:");
	puts (MSG);
	puts (words);
	puts (pt1);
	words [14] = 'ф';
	puts (words);
	
	return 0;
}
