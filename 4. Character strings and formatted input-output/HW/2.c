// Упр. 2, стр. 155
#include<stdio.h>
#include<string.h>

int main(void)
{
	char name[15];

	printf("Введите своё имя:\n");
	scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("%*s\n", strlen(name)+3, name);

	return 0;
}
