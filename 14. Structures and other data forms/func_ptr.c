// func_ptr.c -- использование указателей на функции
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 81
char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void);	// читает до конца строки
void show(void (*fp) (char *), char * str);
void ToUpper(char *);	// преобразует в верхний регистр
void ToLower(char *);	// преобразует в нижний регистр
void Transpose(char *);	// меняет местами регистры
void Dummy(char *);	// оставляет строку неизменной

int main (void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun) (char *);	// указывает на функцию, которая имеет аргумент типа char * и ничего не возвращает
	
	puts("Введите строку (пустая строка - выход из программы):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)		// оператор switch устанавливает указатель
			{
				case 'u': pfun = ToUpper; break;
				case 'l': pfun = ToLower; break;
				case 't': pfun = Transpose; break;
				case 'o': pfun = Dummy; break;
			}
			strcpy(copy, line);	// сделать копию для show()
			show(pfun, copy);	// использовать выбранную функцию
		}
		puts("Введите строку (пустая строка - выход из программы):");
	}
	puts("Программа завершена.");

	return 0;
}

char showmenu (void)
{
	char ans;
	puts("Введите выбранный вариант из меню:");
	puts("u) верхний регистр	l) нижний регистр");
	puts("t) поменять местами регистры	o) исходный регистр");
	puts("n) следующая строка");
	ans = getchar();	// получить ответ
	ans = tolower(ans);	// преобразовать в нижний регистр
	eatline();		// избавиться от оставшейся части строки
	while (strchr("ulton", ans) == NULL)
	{
		puts("Введите u, l, t, o или n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char * str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char * str)
{
	// оставляет строку неизменной
}

void show (void (*fp) (char *), char * str)
{
	(*fp)(str);	// применить выбранную функцию к str
	puts(str);	// отобразить результат
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	if ((ret_val = fgets(st, n, stdin)))
		if ((find = strchr(ret_val, '\n')))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	return ret_val;
}

