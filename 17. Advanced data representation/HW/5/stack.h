// Имя типа:		Стек
// Свойства типа:	Последовательность элементов, построенная по принципу Last in - First out (LIFO)
// Операции типа:	Инициализация стека пустым содержимым
// 			Определение, является ли стек пустым
// 			Определение, является ли стек полным
// 			Определение количества элементов в стеке
// 			Заталкивание элемента в стек
// 			Снятие элемента с вершины стека
// 			Обход стека
// 			Опустошение стека
#ifndef _STACK_H_
#include<stdbool.h>
#define MAXITEMS 45

typedef char Item;

typedef struct stnode
{
	Item item;
	struct stnode * next;
	
} Stnode;

typedef struct stack
{
	Stnode * top;
	unsigned int count;
} Stack;

// операция:	инициализация стека пустым содержимым
// предусловия:	ps указывает на стек
// постусловия:	стек инициализирован пустым содержимым
void InitializeStack (Stack * ps);

// операция:	определение, пуст ли стек
// предусловия:	ps указывает на инициализированный стек
// постусловия:	функция возвращает true, если стек пуст,
// 		и false - в противном случае
bool StackIsEmpty (const Stack * ps);

// операция:	определение, полон ли стек
// предусловия:	ps указывает на инициализированный стек
// постусловия:	функция возвращает true, если стек полон,
// 		и false - в противном случае
bool StackIsFull (const Stack * ps);

// операция:	определение количества элементов в стеке
// предусловия:	ps указывает на инициализированный стек
// постусловия:	функция возвращает количество элементов
// 		в стеке на данный момент
unsigned int CountItemStack (const Stack * ps);

// операция:	заталкивание элемента в стек
// предусловия:	pi указывает на элемент, помещаемый на вершину стека
// 		ps указывает на стек
// постусловия:	если возможно, функция помещает элемент на вершину стека,
// 		возвращая значение true, в противном случае - элемент не
// 		помещается в стек, возвращается значение false
bool Push (Item * pi, Stack * ps);

// операция:	снятие элемента с вершины стека
// предусловия:	pi указывает на область памяти, куда помещается элемент,
// 		снятый со стека, ps указывает на стек
// постусловия:	если возможно, элемент с вершины стека сохраняется по адресу pi,
// 		функция возвращает значение true; в противном случае - возвращается
// 		false
bool Pop (Item * pi, Stack * ps);

// операция:	обход стека
// предусловия:	ps указывает на стек, pfun указывает на функцию,
// 		принимающую Item формальным параметром и ничего не возвращающую
// постусловия:	функция pfun применяется ко всем элементам стека ровно один раз
void Traverse (Stack * ps, void (* pfun) (Item item));

// операция:	опустошение стека
// предусловия:	ps указывает на стек
// постусловия:	стек пуст
void EmptyStack (Stack * ps);
#endif