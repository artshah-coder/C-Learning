/* stack.c -- реализация интерфейса стека */
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void InitializeStack (Stack * ps)
{
	ps->top == NULL;
	ps->count = 0;
}

bool StackIsEmpty (const Stack * ps)
{
	return ps->count == 0;
}

bool StackIsFull (const Stack * ps)
{
	return ps->count == MAXITEMS;
}

unsigned int CountItemStack (const Stack * ps)
{
	return ps->count;
}

bool Push (Item * pi, Stack * ps)
{
	Stnode * pn;

	if (StackIsFull(ps))
		return false;		// если стек полон, выходим из функции, возвращая false

	pn = (Stnode *) malloc (sizeof(Stnode));
	if (NULL == pn)
		return false;		// если не удалось выделить память, выходим из функции, возвращаем false

	pn->item = *pi;

	if (StackIsEmpty(ps))		// если добавляем первый элемент в стек
		pn->next = NULL;	// то указатель next у первого узла будет равен NULL 
	else
		pn->next = ps->top;	// в противном случае, указатель next укажет на прежню вершину стека
	ps->top = pn;
	ps->count++;
	return true;
}

bool Pop (Item * pi, Stack * ps)
{
	Stnode * temp;
	if (StackIsEmpty(ps))
		return false;		// если стек пуст, снимать нечего - выходим
	*pi = ps->top->item;		// если в стеке есть элементы, снимаем элемент с вершины и помещаем по адресу pi
	temp = ps->top;			// сохраняем текущий адрес верхнего узла
	ps->top = ps->top->next;	// переустанавливаем указатель на вершину
	free(temp);			// освобождаем память, занятую прежней вершиной
	ps->count--;			// декрементируем количество элементов в стеке
	return true;
}

void Traverse (Stack * ps, void (* pfun) (Item item))
{
	Stnode * temp;
	for (temp = ps->top; temp != NULL; temp = temp->next)
		(*pfun)(temp->item);
}

void EmptyStack (Stack * ps)
{
	Item i;
	while (!StackIsEmpty(ps))
		Pop(&i, ps);
}
