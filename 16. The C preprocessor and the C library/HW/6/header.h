#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef _header_h_
#define SZ 20
#define COUNT 4
struct names {
	char name[SZ];
	char surname[SZ];
};
int mycomp(const void *, const void *);
void showarray (const struct names *, int);
#endif
