/* list.c -- функции для поддержки операций со списком */
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/* функции интерфейса */
void InitializeList (List * plist)
{
	plist->items = 0;
}

bool ListIsEmpty (const List * plist)
{
	return (plist->items == 0) ? true : false;
}

bool ListIsFull (const List * plist)
{
	return (plist->items == MAXSIZE) ? true : false;
}

unsigned int ListItemCount (const List * plist)
{
	return plist->items;
}

bool AddItem (Item item, List * plist)
{
	if (ListIsFull(plist))
		return false;
	plist->entries[plist->items] = item;
	plist->items++;
	return true;
}

void Traverse (const List * plist, void (* pfun) (Item item))
{

	for (int i = 0; i < plist->items; i++)
		(* pfun) (plist->entries[i]);
}

void EmptyTheList (List * plist)
{
	plist->items = 0;
}
