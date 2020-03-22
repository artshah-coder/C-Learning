// заголовочный файл с определением схемы структуры,
// константами и прототипами используемых в программе функциями
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define PLACES 12	// количество мест в самолете
#define STR 20		// максимальная длина имени/фамилии пассажира

typedef struct {
	int num;	// номер места
	bool free;	// свободно или забронировано место:
			// 1 (true) - свободно; 0 (false) - занято
	char name[STR];	// имя пассажира
	char surn[STR];	// фамилия пассажира
}PLACE;

void eatline (void);
char * s_gets (char *, int);
int ct_free (PLACE *, int);
void ls_free (PLACE *, int);
void ls_booked (PLACE *, int);
void book_place (PLACE *, int);
void free_place (PLACE *, int);
int load_data (FILE *, PLACE *, int);
int writef (FILE *, PLACE *, int);
