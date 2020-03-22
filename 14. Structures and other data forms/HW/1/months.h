// months.h - заголовочный файл, содержащий шаблон структуры и объявление массива структур, используемого в 1.c
typedef struct month {
	char name[20];
	char abbr[4];
	int days;
	int mnumb;
}MONTH;

MONTH months[12] = {
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
