#include<stdio.h>
#include<locale.h>
#define STLEN 5

int main (void)
{
		setlocale (LC_ALL, "Rus");
			char words[STLEN];
				puts ("Input your string:");
					gets (words);
						printf ("Your string output dual:\n");
							printf ("%s\n", words);
								puts (words);
									puts ("Thats all!");
										
										return 0;
}
