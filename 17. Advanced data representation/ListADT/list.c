/* list.c -- функции для поддержки операций со списком */
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
/* прототип локальной функции */
static void CopyToNode(Item item, Node * pnode);

/* функции интерфейса */
/* устанавливает список в пустое состояние */
void InitializeList (List * plist)
{
	*plist = NULL;
}

/* возращает true, если список пуст */
bool ListIsEmpty (const List * plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/* возвращает true, если список полон */
bool ListIsFull (const List * plist)
{
	bool IsFull;
	Node * pnode = (Node *) malloc(sizeof(Node));
	if (pnode == NULL)
		IsFull = true;
	else
		IsFull = false;
	free(pnode);

	return IsFull;
}

/* возвращает количество узлов */
unsigned int ListItemCount (const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;	/* установка в начало списка */

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

/* создает узел для хранения элемента и добавляет его в конец */
/* списка, указанного переменной plist (медленная реализация) */
bool AddItem (Item item, List * plist)
{
	Node * pnew = (Node *) malloc(sizeof(Node));
	Node * pscan = *plist;
	if (pnew == NULL)
		return false;

	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (pscan == NULL)
		*plist = pnew;
	else
	{
		while (pscan->next != NULL)
			pscan = pscan->next;
		pscan->next = pnew;
	}

	return true;
}

/* посещает каждый узел и выполняет функцию, указанную pfun */
void Traverse (const List * plist, void (* pfun) (Item item))
{
	Node * pnode = *plist;	/* установка в начало списка */
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* освобождает память, выделенную функцией malloc() 	*/
/* устанавливает указатель списка в NULL		*/
void EmptyTheList (List * plist)
{
	Node * psave;

	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

/* определение локальной функции */
/* копирует элемент в узел	*/
static void CopyToNode (Item item, Node * pnode)
{
	pnode->item = item;		/* копирование структуры */
}
