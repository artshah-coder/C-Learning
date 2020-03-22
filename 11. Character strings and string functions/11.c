#include<stdio.h>
#include<string.h>

char * s_gets (char * st, int n)
{
	char * ret_val = fgets (st, n, stdin);
	char c;
	if (ret_val)
		if (c = strchr(st, '\n'))
			*c = '\0';
		else
			while (getchar() != '\n')
				continue;

	return ret_val;
}
