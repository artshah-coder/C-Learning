/* tree.c -- функции поддержки дерева */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/* локальный тип данных */
typedef struct pair {
	Trnode * parent;
	Trnode * child;
} Pair;

/* прототипы локальных функций */
static Trnode * MakeNode (const char *);
static bool ToLeft (const char *, const char *);
static bool ToRight (const char *, const char *);
static void AddNode (Trnode *, Trnode *);
static void InOrder (const Trnode *, void (* pfun) (Item item));
static Pair SeekItem (const char *, const Tree *);
static void DeleteNode (Trnode **);
static void DeleteAllNodes (Trnode *);

/* определения функций */
void InitializeTree (Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty (const Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull (const Tree * ptree)
{
	Trnode * pn;
	bool full;
	pn = (Trnode *) malloc (sizeof(Trnode));
	if (pn == NULL)
		full = true;
	else
		full = false;
	free(pn);

	return full;
}

int TreeItemCount (const Tree * ptree)
{
	return ptree->size;
}

bool AddItem (const char * word, Tree * ptree)
{
	Trnode * new_node;
	Trnode * look;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Дерево переполнено\n");
		return false;		/* преждевременный возврат */
	}

	if ((look = SeekItem(word, ptree).child) != NULL)
	{
		look->item.count++;
	}
	else
	{
		new_node = MakeNode(word);	/* указывает на новый узел */
		if (new_node == NULL)
		{
			fprintf(stderr, "Не удалось создать узел");
			return false;		/* преждевременный возврат */
		}
		
		/* успешное зоздание нового узла */
		ptree->size++;
		if (ptree->root == NULL)			/* случай 1: дерево пустое	*/
			ptree->root = new_node;			/* новый узел - корень дерева	*/
		else						/* случай 2 - дерево не пустое	*/
			AddNode(new_node, ptree->root);		/* добавление узла к дереву	*/
	}

	return true;
}

int InTree (const char * word, const Tree * ptree)
{
	Trnode * look; 
	if ((look = SeekItem(word, ptree).child) == NULL)
		return 0;
	else
		return look->item.count;
}

bool DeleteItem (const char * word, Tree * ptree)
{
	Pair look;
	look = SeekItem(word, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)		/* удаление корневого элемента */
		if (look.child->item.count == 1)
		{
			DeleteNode(&ptree->root);
			ptree->size--;
		}
		else
			look.child->item.count--;
	else if (look.parent->left == look.child)
		if (look.parent->left->item.count == 1)
		{
			DeleteNode(&look.parent->left);
			ptree->size--;
		}
		else
			look.parent->left->item.count--;
	else
		if (look.parent->right->item.count == 1)
		{
			DeleteNode(&look.parent->right);
			ptree->size--;
		}
		else
			look.parent->right->item.count--;
	return true;
}

void Traverse (const Tree * ptree, void (* pfun) (Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll (Tree * ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

/* локальные функции */
static void InOrder (const Trnode * root, void (* pfun) (Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes (Trnode * root)
{
	Trnode * pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static void AddNode (Trnode * new_node, Trnode * root)
{
	if (ToLeft(new_node->item.word, root->item.word))
	{
		if (root->left == NULL)			/* пустое поддерево,		*/
			root->left = new_node;		/* поэтому добавить сюда узел	*/
		else
			AddNode(new_node, root->left);	/* иначе обработать поддерево	*/
	}
	else if (ToRight(new_node->item.word, root->item.word))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else						/* дубликаты не допускаются*/
	{
		fprintf(stderr, "Ошибка местоположения в AddNode()\n");
		exit(EXIT_FAILURE);
	}
}

static bool ToLeft (const char * w1, const char * w2)
{
	if (strcmp(w1, w2) < 0)
		return true;
	else
		return false;
}

static bool ToRight (const char * w1, const char * w2)
{
	if (strcmp(w1, w2) > 0)
		return true;
	else
		return false;
}

static Trnode * MakeNode (const char * word)
{
	Trnode * new_node;
	new_node = (Trnode *) malloc (sizeof(Trnode));
	if (new_node != NULL)
	{
		strncpy(new_node->item.word, word, SLEN);
		new_node->item.count = 1;
		new_node->left = new_node->right = NULL;
	}

	return new_node;
}

static Pair SeekItem (const char * word, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
		return look;	/* преждевременый возврат */

	while (look.child != NULL)
	{
		if (ToLeft(word, look.child->item.word))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(word, look.child->item.word))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else	/* если элемент не расположен ни слева, ни справа, он должен быть таким же */
			break;	/* look.child - это адрес узла, содержащего элемент */
	}

	return look;
}

static void DeleteNode (Trnode **ptr)
	/* адрес родительского элемента, указывающего на целевой узел */
{
	Trnode * temp;

	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}

	else	/* удаляемый узел имеет два дочерних узла */
	{
		/* выяснение места присоединения правого поддерева */
		for (temp = (*ptr)->left; temp->right != NULL;
				temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
