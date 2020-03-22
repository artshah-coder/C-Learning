/* animals.c -- использование оператора switch */
#include<stdio.h>
#include<ctype.h>
#include<locale.h>

int main (void)
{
	setlocale(LC_ALL, "Rus");
	char ch;

	printf("Дайте мне букву алфавита, и я укажу вам "
			"название животного,\n начинающегося с этой буквы.\n");
	printf("Введите букву или # для завершения.\n");
	while((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;
		if (islower(ch))
			switch (ch)
			{
				case 'а':
					printf("архар, дикий горный азиатский баран\n");
					break;
				case 'б':
					printf("бабирусса, дикая малайская свинья\n");
					break;
				case 'к':
					printf("коати, носуха обыкновенная\n");
					break;
				case 'в':
					printf("выхухоль, водоплавающее существо\n");
					break;
				case 'е':
					printf("ехидна, игольчатый муравьед\n");
					break;
				case 'р':
					printf("рыболов, светло-коричневая куница\n");
					break;
				default:
					printf("Вопрос озадачил!\n");
			}
		else
			printf("Допустимы только строчные буквы!\n");
		while (getchar() != '\n')
			continue;
		printf("Введите следующую букву или # для завершения.\n");
	}
	printf("До свидания.\n");

	return 0;
}
