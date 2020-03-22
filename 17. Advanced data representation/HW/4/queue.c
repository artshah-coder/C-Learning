/* queue.c -- реализация интерфейса очереди */
#include<stdlib.h>
#include<stdio.h>
#include"queue.h"

void InitializeQueue (Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsEmpty (const Queue * pq)
{
	return pq->items == 0;
}

bool QueueIsFull (const Queue * pq)
{
	return pq->items == MAXITEMS;
}

int QueueItemCount (const Queue * pq)
{
	return pq->items;
}

bool EnQueue (const Item item, Queue * pq)
{
	Node * pn;
	if (QueueIsFull(pq))
		return false;		// очередь полна, добавить элемент не получится
	
	pn = (Node *) malloc (sizeof(Node));
	if (NULL == pn)
		return false;		// если не удалось выделить память под новый узел, прерываем выполнение, возвращаем false

	pn->item = item;
	pn->next = NULL;

	if (QueueIsEmpty(pq))		// если очередь пуста
		pq->front = pn;		// указатель на начало очереди есть указатель на новый элемент
	else				// в противном случа
		pq->rear->next = pn;	// переустанавливаем указатель next хвостового элемента
	pq->rear = pn;			// переустанавливаем указатель на хвостовой элемент
	pq->items++;

	return true;
}

bool DeQueue (Item * pi, Queue * pq)
{
	Node * temp;

	if (QueueIsEmpty(pq))		// если очередь пуста,
		return false;		// извлекать нечего, возвращаем false

	*pi = pq->front->item;		// заносим первый элемент в очерди по адресу pi
	temp = pq->front;		// сохраняем адрес первого узла для очистки памяти
	pq->front = pq->front->next;	// переустанавливаем указатель на первый узел
	free(temp);			// очищаем память, выделенную под бывший первый элемент
	pq->items--;			// декрементируем количество элементов в очереди
	if (pq->items == 0)		// если удалили последний элемент
		pq->rear = NULL;	// переустановим указатель на хвост очереди в NULL	
	return true;
}

void EmptyTheQueue (Queue * pq)
{
	Item i;
	while (!QueueIsEmpty(pq))
		DeQueue(&i, pq);
}
