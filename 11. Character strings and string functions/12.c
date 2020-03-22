#include<stdio.h>
#include<string.h>
#include<ctype.h>

char * srch_space (char * st)
{
	char * ret_val = NULL;
	char * cp_stptr = st;
	if (cp_stptr)
		while (*cp_stptr)
			if (isspace(*cp_stptr))
			{
				ret_val = cp_stptr;
				break;
			}
			else
				cp_stptr++;
	
	return ret_val;
}
