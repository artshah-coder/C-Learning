// library.h -- заголовочный файл со схемами структур, определениями констант
// и прототипами используемых функций
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXTITL 40	// максимальная длина строки названия
#define MAXAUTL 40	// максимальная длина строки имени автора
#define MAXBKS	10	// размер массива структур BOOK

struct book {			// шаблон структуры BOOK
	char title [MAXTITL];	// название
	char author [MAXAUTL];	// автор
	float value;		// цена
};

typedef struct {
	struct book main;
	int status;		// поле-флаг:	1 - структура помечена как удаленная;
				//		2 - структура была изменена;
				//		0 - структура была добавлена.
}BOOK;

char * s_gets (char *, int);	// считывает строку из stdin и заменяет символ новой строки
				// на нулевой символ
void eatline (void);		// удаление лишних символов из буфера потока ввода
void ld (FILE *, BOOK *, int);
void unld (FILE *, BOOK *, int);
int readf (FILE *);
void del_rec (int, BOOK *);
void edit_rec (int, BOOK *);
void add_rec (int, BOOK *);
