// names.h -- добавление защиты от многократного включения

#ifndef NAMES_H_
#define NAMES_H_

// константы
#define SLEN 32

// объявления структур
struct names_st
{
	char first [SLEN];
	char last [SLEN];
};

// определения типов
typedef struct names_st names;

// прототипы функций
void get_names(names *);
void show_names(const names *);
char * s_gets (char * st, int n);

#endif
