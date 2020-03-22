#include<stdio.h>
#include<string.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	printf("%d\n", strlen("ѕук"));

	return 0;
}
