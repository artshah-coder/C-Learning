#include"plane.h"

int ct_free (PLACE * p, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if ((p + i)->free)
			count++;
	return count;
}

void ls_free (PLACE * p, int n)
{
	for (int i = 0; i < n; i++)
		if ((p + i)->free)
			printf("%d ", (p + i)->num);
	printf("\n");
}

void ls_booked (PLACE * p, int n)
{
	int count = 0;
	PLACE temp;
	PLACE * tmp = (PLACE *) malloc (sizeof(PLACE));
	for (int i = 0; i < n; i++)
		if (!p[i].free)
		{
			tmp = (PLACE *) realloc (tmp, sizeof(PLACE)*(++count));
			tmp[count - 1] = p[i];
		}
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (strcmp(tmp[i].surn, tmp[j].surn) > 0)
			{
				temp = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = temp;
			}
	for (int i = 0; i < count; i++)
		printf("%d %s %s.\n", tmp[i].num, tmp[i].surn, tmp[i].name);
}

void book_place (PLACE * p)
{
	p->free = false;
}

void free_place (PLACE * p)
{
	p->free = true;
	p->name[0] = '\0';
	p->surn[0] = '\0';
}

int load_data (FILE * f, PLACE * p, int n)
{
	int index = 0;
	rewind(f);
	while (fread(&p[index], sizeof(PLACE), 1, f) && index < n)
		index++;
	return index;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

char * s_gets (char * st, int n)
{
	char * ret_val = fgets(st, n, stdin);
	char * find;
	if (ret_val)
		if ((find = strchr(ret_val, '\n')))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	return ret_val;
}

int writef (FILE * f, PLACE * p, int n)
{
	rewind(f);
	int index = 0;
	while (fwrite(&p[index], sizeof(PLACE), 1, f) && index < n)
		index++;
	return index;
}
