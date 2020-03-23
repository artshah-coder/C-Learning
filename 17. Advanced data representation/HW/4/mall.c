// mall.c -- использует интерфейс Queue
// компилировать вместе с queue.c
// моделирование консультационного киоска с двумя окошками (2 очереди)
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
	srand((unsigned int) time(NULL));	// задаем начало последовательности для генерации псевдослучайных чисел
	puts("Моделирование киоска с двумя окошками (двумя очередями).");
	puts("Задайте количество часов моделирования:");
	scanf("%d", &hours);
	eatline();
	puts("Задайте среднее количество клиентов, прибывающих в час:");
	scanf("%d", &perhour);
	eatline();
	cyclelimit = hours*MIN_PER_HR;
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)		// отсчет времени - поминутный: от 0 до cyclelimit
	{
		if (newcustomer(min_per_cust))			// если появился новый клиент
		{
			if (QueueIsFull(&line1))		// если полна первая очередь
				if (QueueIsFull(&line2))	// проверяем, полна ли вторая
					turnaways++;		// если полна - инкрементируем счетчик отказов
				else
				{
					temp = customertime(cycle);	// если во второй очереди есть место, задаем параметры
									// клиента (время прибытия и время консультации)
					EnQueue(temp, &line2);		// добавляем клиента во вторую очередь
					customers++;			// инкрементируем число клиентов
				}
			else if (QueueIsFull(&line2))			// если в очереди 1 есть место, а в очереди 2 нет
			{
				temp = customertime(cycle);		// задаем параметры клиента в функции customertime
				EnQueue(temp, &line1);			// добавляем клиента в первую очередь
				customers++;				// инкрементируем число клиентов
			}
			else if (QueueItemCount(&line1) < QueueItemCount(&line2))	// в обоих очередях есть место
			// логично, что клиент встанет в очередь с меньшим колиеством людей
			// если это очередь 1
			{
				temp = customertime(cycle);	// задаем параметры клиента
				EnQueue(temp, &line1);		// добавляем его в очередь 1
				customers++;			// инкрементируем число клиентов
			}
			else if (QueueItemCount(&line1) > QueueItemCount(&line2))
			// если очередь с меньшим числом народу - это очередь 2
			{
				temp = customertime(cycle);	// задаем параметры клиента
				EnQueue(temp, &line2);		// добавляем его в очередь 2
				customers++;			// инкрементируем число клиентов
			}
			else	// число людей в очередях одинаково, выбор клиента, в какую очередь встать случаен
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
		
		if (wait_time1 <= 0 && !QueueIsEmpty(&line1))	// если первый консультант свободен и в очереди 1 есть люди
		{
			DeQueue(&temp, &line1);			// помещаем параметры первого в очереди 1 пользователя в temp
			wait_time1 = temp.processtime;		// задаем время, которое консультант 1 будет занят
			served1++;				// инкрементируем число обслуженных в 1-й очереди клиентов
			line_wait1 += (cycle - temp.arrive); 	// увеличиваем общее время ожидания клиентов в 1-й очереди,
								// добавляя к нему время ожидания текущего клиента
		}
		else if (wait_time1 > 0)	// если консультант 1 занят
			wait_time1--;		// декрементируем время его занятости

		if (wait_time2 <= 0 && !QueueIsEmpty(&line2))	// если второй консультант свободен и в очереди 2 есть люди
		{
			DeQueue(&temp, &line2);			// помещаем параметры первого в очереди 1 пользователя в temp
			wait_time2 = temp.processtime;		// задаем время, которое консультант 2 будет занят
			served2++;				// инкрементируем число обслуженных во 2-й очереди клиентов
			line_wait2 += (cycle - temp.arrive);	// увеличиваем общее время ожидания клиентов во 2-й очереди
		}
		else if (wait_time2 > 0)	// если консультант 2 занят
			wait_time2--;		// декрементируем время его занятости

		sum_line1 += QueueItemCount(&line1);	// увеличиваем общее число людей в очереди 1
		sum_line2 += QueueItemCount(&line2);	// увеличиваем общее число людей в очереди 2

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
	EmptyTheQueue(&line1);	// освобождаем память, занятую под очередь 1
	EmptyTheQueue(&line2);	// освобождаем память, занятую под очередь 2
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
