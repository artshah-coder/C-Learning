// программа-драйвер для функции проверки валидности расстановки скобочек
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

/* прототипы локальных функций */

/* функция строит список open для открывающихся скобок,			*/ 
/* список close для закрывающихся скобок, получая данные из строки str	*/
static void BuildLists (const char * str, List * open, List * close);

/* функция проверки валидности расстановки скобочек в выражении */
/* принимает в качестве параметров список открывающих		*/
/* и закрывающих скобок; возвращает true, если скобки		*/
/* расставлены валидно, false - в противном случае		*/
static bool IsValid (List * open, List * close);

/* функция вывода на экран элемента Item			*/
static void Print (Item item);

/* функция чтения строки с клавиатуры */
char * s_gets (void);

int main (void)
{
	char * str;		// строка со скобками, проверяемая на валидность
	List open;			// список для открывающихся скобок
	List close;			// список для закрывающихся скобок

	puts("Программа читает строку со скобочками вида ()[]{} и проверяет валидность расстановки скобочек в выражении.");
	printf("Пожалуйста, введите вашу строку со скобочками, которую вы хотите проверить на валидность, и нажмите Enter:\n");
	str = s_gets();
	
	if (NULL == str)
	{
		fprintf(stderr, "Ошибка при выделении памяти под строку.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		InitializeList(&open);          // инициализируем первый список
		InitializeList(&close);         // инициализируем второй список
		BuildLists(str, &open, &close); // строим список открывающих и список закрывающих скобок
		
		printf("Вы ввели: %s.\n", str);
		printf("Скобочки в строке расставлены %s.\n", IsValid(&open, &close) ? "верно" : "неверно");	// проверяем валидность строки
		
		// освобождаем память, выделенную под списки скобок
		EmptyTheList(&open);
		EmptyTheList(&close);
		
		// освобождаем память, выделенную под строку str
		free(str);
	}
	
	puts("Программа завершена!");

	return 0;
}

static void BuildLists (const char * str, List * open, List * close)
{
	Item temp;	// временная переменная типа Item для хранения скобки и позиции,
			// в которой она обнаружена в строке

	for (unsigned int i = 0; *(str + i); i++)	// пробегаемся по всем сиволам в строке,
							// пока не встретим 0-символ конца строки
		if (strchr("{[(", *(str + i)))		// если встретили открывающую скобку,
		{
			temp.bracket = *(str + i);	// сохраняем ее
			temp.position = i;		// и ее позицию в строке в переменную temp
			AddItem (temp, open);		// добавляем в список открывающих скобок
		}
		else if (strchr("}])", *(str + i)))	// если встретили закрывающую скобку,
		{
			temp.bracket = *(str + i);	// сохраняем ее
			temp.position = i;		// и ее позицию в переменную temp
			AddItem (temp, close);		// добавляем в список закрывающих скобок
		}
}

static bool IsValid (List * open, List * close)
{
	Node * topen;	// временный указатель для отслеживания положения в списке открывающих скобок
	Node * tclose;	// временный указатель для навигации в списке закрывающих скобок
	Item temp;	// временная переменная типа Item, необходима для передачи параметра в функцию DeleteItem()

	if (open->count != close->count)		// если скобочек не поровну
		return false;				// завершаем функцию, возвращая false
	

	for (topen = open->first; topen != NULL; topen = topen->next)	// пробегаемся по всему списку открывающих скобочек
			switch (topen->item.bracket)
			{
				case '{':
					for (tclose = close->first; tclose != NULL; tclose = tclose->next)	// пробегаемся по всему списку закрывающих скобочек
						if (tclose->item.bracket == '}')				// если найдена соответствующая закрывающая скобка
						{
							if (topen->item.position < tclose->item.position)	// и при этом позиция закрывающей скобки
														// в исходной строке больше позиции
														// парной открывающей скобки
							{
								temp.bracket = tclose->item.bracket;
								temp.position = tclose->item.position;
								DeleteItem (temp, close);			// удаляем этот элемент из списка закрывающих скобок
								break;						// список close обновился, во избежании ошибок
														// 'Segmentation fault', а также лишнего расходования
														// вычислительных, прерываем 
							}
							else
								return false;
						}
						else
							continue;
					break;
				case '[':
					for (tclose = close->first; tclose != NULL; tclose = tclose->next)
						if (tclose->item.bracket == ']')
						{
							if (topen->item.position < tclose->item.position)
							{
								temp.bracket = tclose->item.bracket;
								temp.position = tclose->item.position;
								DeleteItem (temp, close);
								break;
							}
							else
								return false;
						}
						else
							continue;
					break;
				case '(':
					for (tclose = close->first; tclose != NULL; tclose = tclose->next)
						if (tclose->item.bracket == ')')
						{
							if (topen->item.position < tclose->item.position)
							{
								temp.bracket = tclose->item.bracket;
								temp.position = tclose->item.position;
								DeleteItem (temp, close);
								break;
							}
							else
								return false;
						}
						else
							continue;
					break;
			}

	return ListIsEmpty(close);	// если в итоге список закрывающих скобок пуст, значит, скобки расставлены верно
					// в противном случае - неверно
}

static void Print (Item item)
{
	printf("Скобка: %c\tПозиция: %u\n", item.bracket, item.position);
}

char * s_gets (void)
{
	char * ret_val;		// возвращаемое значение - строка С
	char ch;		// переменная для посимвольного сохранения ввода с клавиатуры
	int i;			// переменная счетчик для цикла

	for (i = 1; (ch = getchar()) != '\n' && ch != EOF; i++)		// пока не нажата клавиша ENTER или не сэмулирован конец файла,
									// инкрементируем счетчик цикла
	{
		if (1 == i)						// если первая итерация цикла
		{
			ret_val = (char *) malloc (sizeof(char)*i);	// запрашиваем память под один однобайтовый символ
			if (NULL == ret_val)				// проверяем, выделилась ли память
				return ret_val;				// если память не выделилась, осуществляем преждевременный возврат
			*(ret_val + i - 1) = ch;			// если память выделилась, помещаем в нулевую позицию в возвращаемой строке
									// прочитанный символ
		}
		else							// если не первая итерация
		{
			ret_val = (char *) realloc (ret_val, sizeof(char)*i);	// запрашиваем перераспределение выделенного ранее участка памяти
			if (NULL == ret_val)					// проверяем успешность операции
				return ret_val;					// в случае ошибки при распределении памяти, выходим из функции
			*(ret_val + i - 1) = ch;				// если память выделилась, заносим в следующую позицию в строке
										// прочитанный символ
		}
	}

	ret_val = (char *) realloc (ret_val, sizeof(char)*(i + 1));		// запрашиваем перераспределение памяти, пытаясь увеличить выделенный ранее участок
										// еще на один байт
	if (NULL == ret_val)							// проверяем успешность операции
		return ret_val;
	*(ret_val + i - 1) = '\0';						// если память выделилась, завершаем строку 0-символом
	
	return ret_val;								// возвращаем значение из функции
}
