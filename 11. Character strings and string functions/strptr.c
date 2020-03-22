#include<stdio.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	printf ("%s %p %c\n", "Мы", " -", *"Космические бродяги");
	
	return 0;
}
