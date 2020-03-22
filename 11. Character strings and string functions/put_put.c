// put_put.c -- функции вывода, определенные пользователем
#include<stdio.h>
#include<locale.h>

void put1 (const char *);
int put2 (const char *);

int main (void)
{
	setlocale(LC_ALL, "Rus");
	put1("Если бы у меня было столько денег, ");
	put1("сколько я мог бы потратить,\n");
	printf("Получилось %d символов.\n",
		put2("то я никогда не заботился бы о починке старых башмаков."));
	
	return 0;
}

void put1 (const char * string)
{
	while (*string)
		putchar(*string++);
}

int put2 (const char * string)
{
	int count = 0;
	
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');
	
	return count;
}
