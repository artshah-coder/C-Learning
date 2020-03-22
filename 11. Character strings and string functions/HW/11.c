#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LIM 10 // максимальное количество считываемых с клавиатуры строк
#define SZ 513 // максимальная длина слова

char * s_gets (char *, int);
void sort_ascii (char (*)[SZ], int);
void sort_length (char (*)[SZ], int);
void sort_length_first_word (char (*)[SZ], int);

int main (void)
{
	int count = 0;
	int i, select;
	char a [LIM][SZ];
	printf("Программа сортирует строки разными способами по выбору пользователя.\n");
	printf("Введите не более %d строк, длиной до %d символов (или Enter в начале строки для завершения ввода строк).\n", LIM, SZ-1);
	
	do
		printf("%d-я строка:\n", count + 1);
	while (s_gets(*(a + count), SZ) && **(a + count++) != '\0' && count < LIM);

	do
	{
		printf("Выберете операцию, которую вы хотите применить к введенным вами строкам:\n"
				"1 - вывести на экран;				2 - отсортировать в алфавитном порядке;\n"
				"3 - отсортировать в порядке возрастания длины;	4 - отсортировать в порядке возрастания длины первого слова;\n"
				"5 - выход.\n");
		scanf("%d", &select);
		while (getchar() != '\n')
			continue;
		switch (select)
		{
			case 1:
				puts ("Вы ввели:");
				for (i = 0; i < count; i++)
					if (**(a + i))
						puts(*(a + i));
				break;
			case 2:
				puts("Сортировка в алфавитном порядке:");
				sort_ascii(a, count);
				for (i = 0; i < count; i++)
					if (**(a + i))
						puts(*(a + i));
				break;
			case 3:
				puts("Сортировка в порядке возрастания длины:");
				sort_length(a, count);
				for (i = 0; i < count; i++)
					if (**(a + i))
						puts(*(a + i));
				break;
			case 4:
				puts("Сортировка в порядке возрастания длины первого слова:");
				sort_length_first_word(a, count);
				for (i = 0; i < count; i++)
					if (**(a + i))
						puts(*(a + i));
				break;
			case 5:
				goto ex;
				break;
			default:
				puts("Ошибка ввода! Повторите.");
				break;
		}
	}
	while(1);
ex: puts("Программа завершена!");
		
	return 0;

}

char * s_gets (char * s, int n)
{
	if (fgets (s, n, stdin))
		if (s[strlen(s) - 1] == '\n')
			s[strlen(s) - 1] = '\0';
		else
			while (getchar() != '\n')
				continue;
	return s;
}

void sort_ascii (char (*a) [SZ], int n)
{
	int i, j;
	char temp [SZ];
	for (i = 0; i < n-1; i++)
		for (j = i+1; j < n; j++)
			if (strcmp (*(a + i), *(a + j)) > 0)
			{
				strcpy (temp, *(a + i));
				strcpy (*(a + i), *(a + j));
				strcpy (*(a + j), temp);
			}
}

void sort_length (char (*a) [SZ], int n)
{
	int i, j;
	char temp [SZ];
	for (i = 0; i < n-1; i++)
		for (j = i+1; j < n; j++)
			if (strlen (*(a + i)) > strlen (*(a + j)))
			{
				strcpy (temp, *(a + i));
				strcpy (*(a + i), *(a + j));
				strcpy (*(a + j), temp);
			}
}

void sort_length_first_word (char (*a) [SZ], int n)
{
	int i, iw = 0, il, j, jw = 0, jl;
	char temp [SZ];
	for (i = 0; i < n - 1; i++)
		for (j = i+1; j < n; j++)
		{
			if (**(a + j))
			{
				while (isspace(*(*(a + i) + iw)))
					iw++;
				while (isspace(*(*(a + j) + jw)))
					jw++;
				for (il = 0; !isspace(*(*(a + i) + iw)) && *(*(a + i) + iw); iw++)
					il++;
				for (jl = 0; !isspace(*(*(a + j) + jw)) && *(*(a + j) + jw); jw++)
					jl++;
				if(il > jl)
				{
					strcpy (temp, *(a + i));
					strcpy (*(a + i), *(a + j));
					strcpy (*(a + j), temp);
				}
				il = 0;
				jl = 0;
				iw = 0;
				jw = 0;
			}
		}
}
