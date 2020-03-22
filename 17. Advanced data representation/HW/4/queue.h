/* queue.h -- интерфейс очереди */
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<stdbool.h>
#define MAXITEMS 10

typedef struct item
{
	long arrive;		// время прибытия человека в очередь
	int processtime;	// время консультации
} Item;

typedef struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct queue		// определение типа очереди
{
	Node * front;		// указатель на начало очереди
	Node * rear;		// указатель на конец очереди
	int items;		// количество элементов в очереди
} Queue;

// операция:	инициализация очереди
// предусловие:	pq указывает на очередь
// постусловие:	очередь инициализирована пустым содержимым
void InitializeQueue (Queue * pq);

// операция:	определение, пуста ли очередь
// предусловие:	pq указывает на инициализированную очередь
// постусловие:	функция возвращает true в случае, когда очередь пуста
// 		и false в противном случае
bool QueueIsEmpty (const Queue * pq);

// операция:	определение, полна ли очередь
// предусловие:	pq указывает на инициализированную очередь
// постусловие:	функция возвращает true в случае, когда очередь полна
// 		и false в противном случае
bool QueueIsFull (const Queue * pq);

// операция:	определение количества элементов в очереди
// предусловие:	pq указывает на инициализированную очередь
// постусловие:	функция возвращает количество элементов в очереди
int QueueItemCount (const Queue * pq);

// операция:	добавление элемента в конец очереди
// предусловие:	pq указывает на инициализированную очередь,
// 		item хранит  добавляемый элемент
// постусловие:	если возможно, элемент pi добавляется в очередь,
// 		функция возвращает значние true, иначе -
// 		функция возвращает значение false
bool EnQueue (const Item item, Queue * pq);

// операция:	удаление элемента из начала очереди
// предусловие:	pq указывает на инициализированную очередь
// 		pi указывает на область памяти, куда нужно сохранить
// 		изъятый элемент
// постусловие:	если возможно, элемент из начала очереди сохраняется
// 		по адресу, указанному pi, функция возвращает true
// 		иначе - функция возвращает false
bool DeQueue (Item * pi, Queue * pq);

// операция:	опустошение очереди
// предусловие:	pq указывает на инициализированную очередь
// постусловие:	очередь пуста
void EmptyTheQueue (Queue * pq);

#endif