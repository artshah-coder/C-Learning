#define MNTHL 20	// длина имени месяца
#define ABBR 4		// длина строки для хранения аббревиатуры месяца

void eatline (void);
char * ToLower (char *);

typedef union mnth {	// пользователь может ввести месяц числом или строкой
	char name[MNTHL];
	int mnumr;
}MNTH;

typedef struct date {	// структура для сохранения даты, введенной пользователем
	int day;
	MNTH month;
	int year;
}DATE;

typedef struct month {	// структура для сохранения данных по конкретному месяцу
	char name[MNTHL];
	char abbr[ABBR];
	int days;
	int mnumb;
}MONTH;

MONTH yr[12] = {	// массив структур месяцов для невисокосного года
	{"January", "Jan", 31, 1},
	{"February", "Feb", 28, 2},
	{"March", "Mar", 31, 3},
	{"April", "Apr", 30, 4},
	{"May", "May", 31, 5},
	{"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12}
};

MONTH bis_yr[12] = {	// массив структур месяцов для високосного года
	{"January", "Jan", 31, 1},
	{"February", "Feb", 29, 2},
	{"March", "Mar", 31, 3},
	{"April", "Apr", 30, 4},
	{"May", "May", 31, 5},
	{"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 32, 12}
};
