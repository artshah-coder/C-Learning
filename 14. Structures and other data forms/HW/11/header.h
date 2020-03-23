#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define SZ 100

void transform (double *, double *, int, double (*) (double));
void fill_arr (double *, int);
double inverse (double);
double square (double);
void prnt_arr (double *, int);
