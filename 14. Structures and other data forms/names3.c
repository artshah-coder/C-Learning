// names3.c -- использование указателей и функции malloc()
#include<stdio.h>
#include<string.h>	// для strcpy(), strlen()
#include<stdlib.h>	// для malloc(), free()
#define SLEN 81

struct namect {		// использование указателей
	char * fname;
	char * lname;
	int letters;
};

void getinfo (struct namect *);		// выделение памяти
void makeinfo (struct namect *);
void showinfo (const struct namect *);
void cleanup (struct namect *);		// освобождение памяти

int main (void)
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

void getinfo (struct namect * pst)
{
	char ch;
	int i = 0;
	printf("Введите свое имя.\n");
	pst->fname = (char *) malloc(sizeof(char));
	while ((ch = getchar()) != '\n')
	{
		pst->fname = (char *) realloc(pst->fname, sizeof(char)*(++i + 1));
		*(pst->fname + i - 1) = ch;
	}
	*(pst->fname + i) = '\0';
	i = 0;
	printf("Введите свою фамилию.\n");
	pst->lname = (char *) malloc(sizeof(char));
	while ((ch = getchar()) != '\n')
	{
		pst->lname = (char *) realloc(pst->lname, sizeof(char)*(++i + 1));
		*(pst->lname + i - 1) = ch;
	}
	*(pst->lname + i) = '\0';
}

void makeinfo (struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo (const struct namect * pst)
{
	printf("%s %s, ваше имя и фамилия содержат %d букв.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup (struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
}
