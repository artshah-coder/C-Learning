#include"header.h"

extern char * aligns[];

int main (void)
{
	char ch;
	unsigned int input;
	struct font f = { 1, 12, 0, false, false, false };
	
	printf("Program with menu. Allows set text properties.\n");
	printf("ID	SIZE	ALIGNMENT	B	I	U	\n"
			"%-5u%6u%12s%12s%7s%7s\n", f.id, f.sz, aligns[f.align], f.bold ? "on" : "off", f.italic ? "on" : "off",
			f.underline ? "on" : "off");
	printf("f) - change font's id	s) - change font's size	a) - change alignment\n"
			"b) - bold	i) - italic	u) - underline\n"
			"e) - exit\n");
	ch = getchar();
	ch = tolower(ch);
	while (strchr("fsabiue", ch) == NULL)
	{
		printf("Input error!\n"
				"Please, input f, s, a, b, i, u or e:\n");
		eatline();
	}
	eatline();
	
	while (ch != 'e')
	{
		switch (ch)
		{
			case 'f':
				printf("Input font's id (0-255):\n");
				while (scanf("%u", &input) != 1 || input < 0 || input > 255)
				{
					printf("Input error!\n"
							"Please, input 0-255 value:\n");
					eatline();
				}
				eatline();
				f.id = input & ID_MASK;
				break;
			case 's':
				printf("Input font's size (0-127):\n");
				while (scanf("%u", &input) != 1 || input < 0 || input > 127)
				{
					printf("Input error!\n"
							"Please, input 0-127 value:\n");
					eatline();
				}
				eatline();
				f.sz = input & SZ_MASK;
				break;
			case 'a':
				printf("Choose alignment:\n"
						"0 - left;	1 - center;	2 - right.\n");
				while (scanf("%u", &input) != 1 || input < 0 || input > 2)
				{
					printf("Input error!\n"
							"Please, input 0-2 value:\n");
					eatline();
				}
				eatline();
				f.align = input;
				break;
			case 'b':
				f.bold = ~f.bold;
				break;
			case 'i':
				f.italic = ~f.italic;
				break;
			case 'u':
				f.underline = ~f.underline;
				break;
		}
		printf("ID      SIZE    ALIGNMENT       B       I       U       \n"
				"%-5u%6u%12s%12s%7s%7s\n", f.id, f.sz, aligns[f.align], f.bold ? "on" : "off", f.italic ? "on" : "off",
				f.underline ? "on" : "off");
		printf("f) - change font's id   s) - change font's size a) - change alignment\n"
				"b) - bold      i) - italic     u) - underline\n"
				"e) - exit\n");
		ch = getchar();
		ch = tolower(ch);
		while (strchr("fsabiue", ch) == NULL)
		{
			printf("Input error!\n"
					"Please, input f, s, a, b, i, u or e:\n");
			eatline();
		}
		eatline();
	}
	printf("\nThe end.\n");

	return 0;
}
