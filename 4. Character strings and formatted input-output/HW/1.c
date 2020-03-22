//Упр. 1, стр. 155
#include<stdio.h>

int main(void)
{
	char name[15], surname[15];
	printf("Введите свои имя и фамилию через пробел и нажмите 'Enter':\n");
	scanf("%s %s", name, surname);
	printf("Фамилия, имя: %s, %s\n", surname, name);

	return 0;
}
