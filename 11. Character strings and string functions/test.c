#include<stdio.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	char * p1 = "�������";
	p1[0] = '�';
	printf ("�������");
	printf ("���������� %s���!\n", "�������");
	
	return 0;
}
