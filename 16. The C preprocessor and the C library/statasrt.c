// statasrt.c
#include<stdio.h>
#include<limits.h>
#include<assert.h>

static_assert(CHAR_BIT == 16, "Error predict 16-bits char type");

int main (void)
{
	puts("Тип char имеет 16 битов.");

	return 0;
}
