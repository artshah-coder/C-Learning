// pe12-8.c -- инициализация и отображение динамического массива
#include<stdio.h>
#include<stdlib.h>

int * make_array (int elem, int value);
void show_array (const int ar[], int n);

int main (void)
{
	int * pa;
	int size;
	int value;
	printf("Введите количество элементов: ");
	while (scanf("%d", &size) == 1 && size > 0)
	{
		printf("Введите значение для инициализации: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Введите количество элементов (<1 для завершения): ");
	}
	
	free(pa);	// освобождаем выделенную память
	printf("Программа завершена.\n");

	return 0;
}

int * make_array (int elem, int value)
{
	int * ret_value = (int *) malloc(elem*sizeof(int));
	if (NULL != ret_value)
		for (int i = 0; i < elem; i++)
			*(ret_value + i) = value;
	return ret_value;
}

void show_array (const int ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d	", ar[i]);
		if (!((i+1)%8))
			putchar('\n');
	}
	if(i%8)
		putchar('\n');
}
