/* mod_str.c -- ������������ ������ */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
#define LIMIT 81

void ToUpper(char *);
int PunctCount (const char *);

int main (void)
{
	char line [LIMIT];
	char * find;
	
	setlocale(LC_ALL, "Russian");
	puts ("������� ������:");
	fgets (line, LIMIT, stdin);
	find = strchr (line, '\n');
	if (find)
		*find = '\0';
	else
		while (getchar() != '\n')
			continue;
	ToUpper(line);
	puts(line);
	printf("��� ������ �������� %d ������ ����������.\n", PunctCount (line));

	return 0;
}

void ToUpper (char * st)
{
	while (*st)
	{
		*st = toupper(*st);
		st++;
	}
}

int PunctCount (const char * string)
{
	int count = 0;
	while (*string)
	{
		if (ispunct(*string))
			count++;
		string++;
	}
	
	return count;
}
