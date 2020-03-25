// list.c -- функции для поддержки операций со списком
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/* реализация функций интерфейса	*/

/* устанавливает список в пустое состояние */
void InitializeList (List * plist)
{
	plist->first = NULL;	// устанавливаем указатель на первый элемент в NULL
	plist->count = 0;	// устанавливаем количество элементов в списке в 0
}

/* проверка, пуст ли список	*/
bool ListIsEmpty (const List * plist)
{
	return (plist->count == 0);	// возвращаем результат логического выражения
					// проверки на равенство нулю поля количества элементов в списке
}

/* проверка, полон ли список	*/
bool ListIsFull (const List * plist)
{
	bool IsFull;
	Node * pnode = (Node *) malloc (sizeof (Node));	// запрашиваем память под новый узел списка
	if (NULL == pnode)				// если памяь выделить не удалось
		IsFull = true;				// список переполнен
	else
		IsFull = false;				// иначе, место еще есть, список не полон
	free (pnode);					// освобождаем память

	return IsFull;					// возвращаем результат
}

/* возвращает количество узлов списка	*/
unsigned int ListItemCount (const List * plist)
{
	return plist->count;	// возвращаем поле count структуры List списка plist
}

/* создает узел для хранения элемента и добавляет его в конец списка */
bool AddItem (Item item, List * plist)
{
	Node * pscan;					// указатель на узел списка,
							// необходимый для навигации по списку plist
	Node * pnew = (Node *) malloc (sizeof (Node));	// запрашиваем память под новый узел
	if (NULL == pnew)	// если память не выделилась
		return false;	// преждевременный возврат из функции со значением false
	
	// если память выделена, заполняем поля вновь созданного узла списка:
	pnew->item = item;
	pnew->next = NULL;
	
	if (ListIsEmpty(plist))		// если plist - пуст
		plist->first = pnew;	// выставляем указатель на первый узел списка plist
					// во вновь созданный узел
	
	else				// если в списке есть узлы
	{
		for (pscan = plist->first; pscan->next != NULL; pscan = pscan->next)	// находим последний узел в списке
			continue;
		pscan->next = pnew;	// в последнем узле устанавливаем указатель next на вновь созданный узел
	}

	plist->count++;		// после добавления узла, инкрементируем счетчик узлов в списке

	return true;		// возвращаем true в случае прохождения всех шагов по добавлению узла в список
}

/* удаляет узел с элементом из списка и актуализирует список	*/
bool DeleteItem (Item item, List * plist)
{
	Node * previous = NULL;		// указатель на предыдущий узел в списке
	Node * current = plist->first;	// указатель на текущий узел в списке

	while (NULL != current)		// пока указатель на текущий узел не NULL
		if (current->item.bracket == item.bracket && current->item.position == item.position)	// если элемент в узле равен искомому
		{
			if (NULL == previous)	// и указатель на предыдущий узел NULL
			{
				plist->first = current->next;	// указатель на первый узел списка ставим в указатель на следующий
				free (current);					// освобождаем память, выделенную под текущий узел 
				plist->count--;					// декрементируем количество элементов в списке
			}
			else			// иначе
			{
				previous->next = current->next;	// переустанавливаем поле next указателя на предыдущий узел
				free (current);			// освобождаем память, выделенную под текущий узел
				plist->count--;			// декрементируем количество элементов в списке
			}
			
			return true;				// возвращаем true: элемент найден в списке, узел, его содержащий, удален
		}
		else
		{
			previous = current;				// переустанавливаем указатель на предыдущий узел в текущий
			current = current->next;			// переустанавливаем указатель на текущий узел в следующий
		}

	return false;	// возвращаем false, если просмотрен весь список и так и не найде искомый для удаления элемент
}

/* посещает каждый узел и выполняет функцию, указанную pfun	*/
void Traverse (const List * plist, void (* pfun) (Item item))
{
	Node * pnode = plist->first;	// установка в начало списка
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* освобождает память, выделенную функцией malloc() под список	*/
/* устанавливает список в пустое состояние			*/
void EmptyTheList (List * plist)
{
	Node * psave = plist->first;	// указатель для отслеживания еще не освобожденного участка памяти
					// который будет особожден первым

	while (NULL != plist->first)
	{
		psave = psave->next;
		free (plist->first);
		plist->first = psave;
	}
	
	plist->count = 0;		// устанавливаем количество узлов списка в 0 после очистки 
}
