#include<stdio.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	printf ("%s %p %c\n", "��", " -", *"����������� �������");
	
	return 0;
}
