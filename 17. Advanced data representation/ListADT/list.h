/* list.h -- заголовочный файл для простого типа списка */
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>	/* функциональная возможность С99 */

/* Объявления, специфичные для программы */
#define TSIZE	45	/* размер массива для хранения названия */
struct film {
	char title[TSIZE];
	int rating;
};
/* определения общих типов */

typedef struct film Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef Node * List;

/* прототипы функций */
/* операция: инициализация списка 				*/
/* предусловия: plist указывает на список			*/
/* постусловия: список инициализирован пустым  содержимым	*/
void InitializeList (List * plist);

/* операция: определение, является ли список пустым		*/
/* предусловия: plist указывает на инициализированный список	*/
/* постусловия: функция возвращает значение true, если список 	*/
/* 		пуст, и false в противном случае		*/
bool ListIsEmpty (const List * plist);

/* операция: определение, является ли список полным		*/
/* предусловия: plist указывает на инициализированный список	*/
/* постусловия: функция взвращает значение true, если список	*/
/*		полон, и false в противном случае		*/
bool ListIsFull (const List * plist);

/* операция: определение количества элементов в списке		*/
/* 		plist указывает на инициализированный список	*/
/* постусловия: функция возвращает число элементов в списке	*/
unsigned int ListItemCount (const List * plist);

/* операция: добавление элемента в конец списка			*/
/* предусловия: item - элемент, добавляемый в список		*/
/*		plist указывает на инициализированный список	*/
/* постусловия: если возможно, функция добавляет элемент в	*/
/*		конец списка и возвращает значение true;	*/
/*		в противном случае возвращается значение false	*/
bool AddItem (Item item, List * plist);

/* операция: применение функции к каждому элементу списка	*/
/* 		plist указывает на инициализированный список	*/
/*		pfun указывает на функцию, которая принимает	*/
/*		аргумент Item и не имеет возвращаемого значения	*/
/* постусловия: функция, указанная pfun, выполняется один раз	*/
/*			для каждого элемента в списке		*/
void Traverse (const List * plist, void (* pfun)(Item item));

/* операция: освобождение выделенной памяти, если она есть	*/
/*		plist указывает на инициализированный список	*/
/* постусловия: любая память, выделенная для списка,		*/
/* 		освобождается, и список устанавливается		*/
/*		в пустое состояние				*/
void EmptyTheList (List * plist);
#endif
