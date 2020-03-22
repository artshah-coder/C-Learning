/* starsrch.c -- использование функции strncmp() */
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define LISTSIZE 6

int main (void)
{
	setlocale (LC_ALL, "Rus");
	const char * list[LISTSIZE] = {
		"астрономия", "астатизм",
		"астрофизика", "остракизм",
		"астеризм", "астролябия"
	};
	
	int count = 0;
	int i;
	
	for (i = 0; i < LISTSIZE; i++)
		if (strncmp (list[i], "астро", 5) == 0)
		{
			printf("Найдено: %s\n", list[i]);
			count++;
		}
	printf("Количество слов в списке,"
			" начинающихся с астро: %d\n", count);

	return 0;
}
