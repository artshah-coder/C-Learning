#define NL 40
#define SL 40
#define PL 40

typedef struct person {		// структура, хранящая ФИО пользователя
	char name[NL];
	char patronymic[PL];
	char surname[SL];
}PERSON;

typedef struct insr {		// структура, хранящая номер страховки пользователя
	unsigned int num;	// и его ФИО во вложенной структуре PERSON
	PERSON p;
}INSR;

void prntstrct (INSR);
