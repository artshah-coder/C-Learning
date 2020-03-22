/* names1.c -- использует указатели на структуры */
#include<stdio.h>
#include<string.h>
#define NLEN 30
struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
char * s_gets(char *, int);

int main(void)
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);

	return 0;
}

void getinfo (struct namect * pst)
{
	printf("Введите свое имя.\n");
	s_gets(pst->fname, NLEN);
	printf("Введите свою фамилию.\n");
	s_gets(pst->lname, NLEN);
}

void makeinfo (struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo (const struct namect * pst)
{
	printf("%s %s, ваше имя и фамилия содержит %d букв.\n", pst->fname, pst->lname, pst->letters);
}

char * s_gets (char * st, int n)
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
