// arrchar.c -- массив указателей, массив строк
#include<stdio.h>
#include<locale.h>
#define SLEN 40
#define LIM 5

int main (void)
{
	setlocale (LC_ALL, "Rus");
	const char * mytalents [LIM] = {
	"Мгновенное складывание чисел",
	"Точное умножение", "Накапливание данных",
	"Исполнение инструкций с точностью до буквы",
	"Знание языка программирования С"
	};
	
	char yourtalents[LIM][SLEN] = {
	"Хождение по прямой",
	"Здоровый сон", "Просмотр телепередач",
	"Рассылка писем", "Чтение электронной почты"
	};
	
	int i;
	
	puts ("Сравним наши таланты.");
	printf ("%-52s %-25s\n", "Мо таланты", "Ваши таланты");
	for (i = 0; i < LIM; i++)
		printf ("%-52s %-25s\n", mytalents[i], yourtalents[i]);
	printf("\nразмер mytalents: %zd, размер yourtalents: %zd\n",
		sizeof (mytalents), sizeof (yourtalents));
	
	return 0;
}
