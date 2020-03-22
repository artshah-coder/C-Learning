// names_st.h -- заголовочный файл для структуры names_st
// константы
#include<string.h>
#define SLEN 32

// объявления структур
struct names_st
{
	char first [SLEN];
	char last [SLEN];
};

// определения типов
typedef struct names_st names;

// прототип функций
void get_names (names *);
void show_names (const names *);
char * s_gets (char * st, int n);
