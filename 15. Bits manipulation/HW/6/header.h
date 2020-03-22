#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define ID_MASK 0xFF
#define SZ_MASK 0x7F

struct font{
	unsigned int id		: 8;
	unsigned int sz		: 7;
	unsigned int align	: 2;
	bool bold		: 1;
	bool italic		: 1;
	bool underline		: 1;	
};

static char * aligns [3] = {"left", "center", "right"};
void eatline(void);
