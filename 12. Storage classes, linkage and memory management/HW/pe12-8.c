// pe12-8.c -- инициализация и отображение динамического массива
#include<stdio.h>
#include<stdlib.h>

// прототипы локальных функций
int * make_array (int elem, int value);		// создание и инициализация массива
void show_array (const int ar[], int n);	// отображение массива на экране

int main (void)
{
	int * pa;	// указатель на динамический массив
	int size;	// переменная для хранения размера массива, вводимого пользователем
	int value;	// значение для инициализации массива
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
