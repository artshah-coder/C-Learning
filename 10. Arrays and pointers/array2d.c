// array2d.c -- функции для двумерных массивов
#include<stdio.h>
#define ROWS 3
#define COLS 4

void sum_rows (int ar[][COLS], int rows);
void sum_cols (int [][COLS], int);
int sum2d (int (*ar) [COLS], int rows);

int main (void)
{
	int junk [ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Сумма всех элементов массива = %d\n", sum2d (junk, ROWS));

	return 0;
}

void sum_rows (int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for (r = 0; r < rows; r++)
	{
		tot = 0;
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
		printf("Строка %d: сумма = %d\n", r, tot);
	}
}

void sum_cols (int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for (c = 0; c < COLS; c++)
	{
		tot = 0;
		for (r = 0; r < rows; r++)
			tot += ar[r][c];
		printf("Столбец %d: сумма = %d\n", c, tot);
	}
	
}

int sum2d (int (*ar) [COLS], int rows)
{
	int r, c;
	int total = 0;
	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++)
			total += *(*(ar + r) + c);
	return total;

}

