// mall.c -- использует интерфейс Queue
// компилировать вместе с queue.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"queue.h"
#define MIN_PER_HR	60.0	// минут в часе

bool newcustomer (double x);	// имеется ли новый клиент
Item customertime (long when);	// установка параметров клиента
void eatline (void);		// чтение символов из буфера ввода, вплоть до символа '\n'

int main (void)
{
	Queue line1, line2;	// две очереди
	Item temp;		// данные о новом клиенте
	int hours;		// количество часов моделирования
	int perhour;		// среднее количество прибывающих в час клиентов
	long cycle, cyclelimit;	// счетчик и граничное значение цикла
	long turnaways = 0;	// количество отказов из-за переполнения очередей
	long customers = 0;	// количество клиентов, присоединившихся к одной из очереди
	long served1 = 0;	// количество обслуженных в 1-ой очереди клиентов
	long served2 = 0;	// количество обслуженных во 2-ой очереди клиентов
	long sum_line1 = 0;	// накопительное значение длины первой очереди
	long sum_line2 = 0;	// накопительное значение длины второй очереди
	int wait_time1 = 0;	// время до освобождения первого консультанта
	int wait_time2 = 0;	// время до освобождения второго консультанта
	long line_wait1 = 0;	// накопительное значение времени в первой очереди
	long line_wait2 = 0;	// накопительное значение времени во второй очереди
	double min_per_cust;	// среднее время между прибытиями клиентов

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int) time(NULL));
	puts("Моделирование киоска с двумя окошками (двумя очередями).");
	puts("Задайте количество часов моделирования:");
	scanf("%d", &hours);
	eatline();
	puts("Задайте среднее количество клиентов, прибывающих в час:");
	scanf("%d", &perhour);
	eatline();
	cyclelimit = hours*MIN_PER_HR;
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (QueueIsFull(&line1))
				if (QueueIsFull(&line2))
					turnaways++;
				else
				{
					temp = customertime(cycle);
					EnQueue(temp, &line2);
					customers++;
				}
			else if (QueueIsFull(&line2))
			{
				temp = customertime(cycle);
				EnQueue(temp, &line1);
				customers++;
			}
			else if (QueueItemCount(&line1) < QueueItemCount(&line2))
			{
				temp = customertime(cycle);
				EnQueue(temp, &line1);
				customers++;
			}
			else if (QueueItemCount(&line1) > QueueItemCount(&line2))
			{
				temp = customertime(cycle);
				EnQueue(temp, &line2);
				customers++;
			}
			else
			{
				switch (rand() % 2 + 1)
				{
					case 1:
						temp = customertime(cycle);
						EnQueue(temp, &line1);
						customers++;
						break;
					case 2:
						temp = customertime(cycle);
						EnQueue(temp, &line2);
						customers++;
						break;
				}
			}
		}
		
		if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp, &line1);
			wait_time1 = temp.processtime;
			served1++;
			line_wait1 += (cycle - temp.arrive); 
		}
		else if (wait_time1 > 0)
			wait_time1--;

		if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp, &line2);
			wait_time2 = temp.processtime;
			served2++;
			line_wait2 += (cycle - temp.arrive);
		}
		else if (wait_time2 > 0)
			wait_time2--;

		sum_line1 += QueueItemCount(&line1);
		sum_line2 += QueueItemCount(&line2);

	}

	if (customers > 0)
	{
		printf("Принятых клиентов:			%ld\n", customers);
		printf("Обслуженных клиентов:			%ld\n", served1 + served2);
		printf("Отказов:				%ld\n", turnaways);
		printf("Средняя длина 1-й очереди:		%.2f\n",
				(double) sum_line1 / cyclelimit);
		printf("Средняя длина 2-й очереди:		%.2f\n",
				(double) sum_line2 / cyclelimit);
		printf("Среднее время ожидания в 1-й очереди:	%.2f мин\n",
				(double) line_wait1/served1);
		printf("Среднее время ожидания во 2-й очереди:	%.2f мин\n",
				(double) line_wait2/served2);
	}
	else
		puts("Клиенты отсутствуют!");
	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	puts("Программа завершена!");

	return 0;
}

bool newcustomer (double x)
{
	if ((rand() * x)/RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime (long when)
{
	Item temp;
	temp.arrive = when;
	temp.processtime = rand() % 3 + 1;
	return temp;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}
