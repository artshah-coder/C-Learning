// list.h - заголовочный файл для пакета односвязного списка
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>

typedef struct item
{
	char bracket;		// скобка
	unsigned int position;	// позиция скобки в строке
} Item;	// определяем новый тип, данные которого будут располагаться в узлах списка

typedef struct node
{
	Item item;		// элемент узла
	struct node * next;	// указатель на следующий узел
} Node;	// определяем тип данных узел односвязного списка

typedef struct list 
{
	Node * first;		// указатель на первый узел списка
	unsigned int count;	// количество элементов в списке
} List;	// определяем тип данных односвязный список в виде указателя на первый узел

/* прототипы функций */
/* операция:	инициализация списка				*/
/* предусловия:	plist указывает на список			*/
/* постусловия:	список инициализирован пустым содержимым	*/
void InitializeList (List * plist);

/* операция:	определение, является ли список пустым		*/
/* предусловия:	plist указывает на инициализированный список	*/
/* постусловия:	функция возвращает true, если список пуст,	*/
/*		и false - в противном случае			*/
bool ListIsEmpty (const List * plist);

/* операция:	определение, является ли список полным		*/
/* предусловия:	plist указывает на инициализированный список	*/
/* постусловия:	функция возвращает true, если список полон,	*/
/*		и false - в противном случае			*/
bool ListIsFull (const List * plist);

/* операция:	определение количества элементов в списке	*/
/* предусловия:	plist указывает на инициализированный список	*/
/* постусловия:	функция возвращает число элементов в списке	*/
unsigned int ListItemCount (const List * plist);

/* операция:	добавление элемента в конец списка		*/
/* предусловия:	item - элемент, добавляемый в список		*/
/*		plist указывает на инициализированный список	*/
/* постусловия:	если возможно, функция добавляет элемент	*/
/*		конец списка и возвращает true;			*/
/*		в противном случае возвращается false		*/
bool AddItem (Item item, List * plist);

/* операция:	удаление элемента из списка			*/
/* предусловия:	item - удаляемый элемент, plist указывает на	*/
/*		инициализированный список			*/
/* постусловия:	если возможно, функция удаляет элемент		*/
/*		из списка, возвращая значение true;		*/
/*		иначе возвращается false			*/
bool DeleteItem (Item item, List * plist);

/* операция:	применение функции к каждому элементу списка	*/
/* предусловия:	plist указывает на инициализированный список	*/
/*		pfun указывает на функцию, которая принимает	*/
/*		аргумент Item и не имеет возвращаемого значения	*/
/* постусловия:	функция, указанная pfun, выполняется один раз	*/
/*		для каждого элемента в списке			*/
void Traverse (const List * plist, void (* pfun) (Item item));

/* операция:	освобождение выделенной памяти, если она есть	*/
/* предусловия:	plist указывает на инициализированный список	*/
/* постусловия:	любая память, выделенная для списка,		*/
/*		освобождается, и список устанавливается		*/
/*		в пустое состояние				*/
void EmptyTheList (List * plist);
#endif
