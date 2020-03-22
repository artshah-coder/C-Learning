/* letkead2.c */
#include<stdio.h>
#include<string.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char (char ch, int num);

int main (void)
{
	int spaces;
	show_n_char('*', WIDTH);
	printf("\n");
	spaces = (WIDTH - strlen(NAME)) / 2;
	show_n_char(SPACE, spaces);
	printf(NAME);
	printf("\n");
	spaces = (WIDTH - strlen(ADDRESS)) / 2;
	show_n_char(SPACE, spaces);
	printf(ADDRESS);
	printf("\n");
	spaces = (WIDTH - strlen(PLACE)) / 2;
	show_n_char(SPACE, spaces);
	printf(PLACE);
	printf("\n");
	show_n_char('*', WIDTH);
	printf("\n");

	return 0;
}

void show_n_char (char ch, int num)
{
	int count;
	for (count = 1; count <= num; count++)
		putchar(ch);
}
