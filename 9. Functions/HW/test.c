#include<stdio.h>

int max (int x, int y, int z)
{
	return ((x > y ? x : y) > z) ? (x > y ? x : y) : z;
}

int main (void)
{

	return 0;
}
