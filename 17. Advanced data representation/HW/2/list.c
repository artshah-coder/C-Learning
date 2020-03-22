/* list.c -- функции для поддержки операций со списком */
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/* функции интерфейса */
void InitializeList (List * plist)
{
	plist->head = plist->end = NULL;
}

bool ListIsEmpty (const List * plist)
{
	if (NULL == plist->head && NULL == plist->end)
		return true;
	else
		return false;
}

bool ListIsFull (const List * plist)
{
	Node * pt;
	bool full;

	pt = (Node *) malloc (sizeof(Node));
	if (pt)
		full = false;
	else
		full = true;
	free (pt);
	return full;
}

unsigned int ListItemCount (const List * plist)
{
	unsigned int count = 0;
	Node * temp;

	for (temp = plist->head; temp != NULL; temp = temp->next)
		count++;

	return count;
}

bool AddItem (Item item, List * plist)
{
	if (ListIsFull(plist))
		return false;

	Node * pt;

	pt = (Node *) malloc (sizeof(Node));
	if (NULL == pt)
		return false;
	
	pt->item = item;
	pt->next = NULL;

	if (ListIsEmpty(plist))
	{
		plist->head = pt;
		plist->end = pt;
	}
	else
	{
		plist->end->next = pt;
		plist->end = pt;
	}
		return true;
}

void Traverse (const List * plist, void (* pfun) (Item item))
{
	Node * temp;

	for (temp = plist->head; temp != NULL; temp = temp->next)
		(* pfun) (temp->item);
}

void EmptyTheList (List * plist)
{
	Node * temp;

	for (temp = plist->head; temp != NULL; temp = plist->head)
	{
		plist->head = plist->head->next;
		free (temp);
	}
	plist->end = NULL;
}
