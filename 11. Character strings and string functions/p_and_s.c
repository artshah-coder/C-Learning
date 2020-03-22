/* p_and_s.c -- указатели и строки */
#include<stdio.h>
#include<locale.h>

int main (void)
{
	setlocale (LC_ALL, "Rus");
	const char * mesg = "Ќе дайте еб€ запутать!";
	const char * copy;
	
	copy = mesg;
	printf ("%s\n", copy);
	printf ("mesg = %s; &mesg = %p; value = %p\n",
		mesg, &mesg, mesg);
	printf ("copy = %s; &copy = %p, value = %p\n",
		copy, &copy, copy);
	
	return 0;
}
