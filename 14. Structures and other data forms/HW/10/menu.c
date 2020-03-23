#include"menu.h"

int get_str (char * str)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) != '\n')
	{
		str = (char *) realloc(str, sizeof(char)*(++i));
		if (NULL == str)
		{
			fprintf(stderr, "Ошибка при выделении памяти.\n");
			exit(EXIT_FAILURE);
		}
		*(str + i - 1) = ch;
	}
	*(str + i) = '\0';
	if (str)
		return (1);
	else
		return (0);
}

void ToUpper (char * str)
{
	int i = 0;
	while (*str)
	{
		*str = toupper(*str);
		str++;
		i++;
	}
	printf("Преобразованная строка: %s.\n", str - i);
}

void ToLower (char * str)
{
	int i = 0;
	while (*str)
	{
		*str = tolower(*str);
		str++;
		i++;
	}
	printf("Преобразованная строка: %s.\n", str - i);
}

void invert_str (char * str)
{
	char tmp;
	for (int i = 0; i < strlen(str)/2; i++)
	{
		tmp = *(str + i);
		*(str + i) = *(str + (int) strlen(str) - i - 1);
		*(str + (int) strlen(str) - i - 1) = tmp;
	}
	printf("Преобразованная строка: %s.\n", str);
}

void Change_Reg (char * str)
{
	int i = 0;
	while (*str)
	{
		if (isupper(*str))
			*str = tolower(*str);
		else
			if (islower(*str))
				*str = toupper(*str);
		str++;
		i++;
	}
	printf("Преобразованная строка: %s.\n", str - i);
}

void ct_smbls (char * str)
{
	int i = 0;
	while (*str++)
		i++;
	printf("Во введенной вами строке %d символов.\n", i);
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}
