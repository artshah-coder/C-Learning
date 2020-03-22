#include<stdio.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char * p1 = "Клингон";
	p1[0] = 'Ф';
	printf ("Клингон");
	printf ("Берегитесь %sцев!\n", "Клингон");
	
	return 0;
}
