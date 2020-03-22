#include"header.h"

int mycomp (const void * p1, const void * p2)
{
	const struct names * a1 = (const struct names *) p1;
	const struct names * a2 = (const struct names *) p2;
	
	if (strcmp(a1->surname, a2->surname) > 0)
		return 1;
	else if (strcmp(a1->surname, a2->surname) == 0)
		if(strcmp(a1->name, a2->name) > 0)
			return 1;
		else
			return -1;
	else
		return -1;
}

void showarray (const struct names * ps, int n)
{
	for (int i = 0; i < n; i++)
		printf("%s %s\n", (ps + i)->surname, (ps + i)->name);
}
