// Упр. 6, стр. 155
#include<stdio.h>
#include<string.h>

int main(void)
{
	char name[15], surname[15];
	printf("Введите своё имя и фамилию через пробельный символ:\n");
	scanf("%s %s", name, surname);
	printf("%s %s\n%-*lu %-*lu\n", name, surname, strlen(name), strlen(name), strlen(surname), strlen(surname));

	return 0;
}
