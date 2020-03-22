/* friends.c -- использование указателя на структуру */
#include<stdio.h>
#define LEN 40

struct names {
	char first[LEN];
	char last[LEN];
};

struct guy {
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main (void)
{
	struct guy fellow[2] = {
		{{ "Билли", "Бонс" },
			"запеченными омарами",
			"персональный тренер",
			68112.00
		},
		{{ "Джим", "Хокинс" },
			"рыбным фрикасе",
			"редактор таблоида",
			232400.00
		}
	};
	struct guy * him;	/* указатель на структуру */
	printf("адрес #1: %p #2: %p\n", fellow, fellow + 1);
	him = fellow;	/* сообщает указателю, на что указывать */
	printf("указатель #1: %p #2: %p\n", him, him + 1);
	printf("him->income равно $%.2f: (*him).income равно $%.2f\n",
			him->income, (*him).income);
	him++;	/* указатель на следующую структуру */
	printf("him->favfood равно %s: him->handle.last равно %s\n", him->favfood, him->handle.last);

	return 0;
}
