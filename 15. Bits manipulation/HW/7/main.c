#include"header.h"

extern char * aligns[];

int main (void)
{
	char ch;
	unsigned int input;
	unsigned long data = 0;
	data = 1 + (12 << 8) + (0 << 15) + (0 << 17) + (0 << 18) + (0 << 19);

	
	printf("Program with menu. Allows set text properties.\n");
	printf("ID	SIZE	ALIGNMENT	B	I	U	\n"
			"%-5u%6u%12s%12s%7s%7s\n", data & ID_MASK, (data & SZ_MASK) >> 8, aligns[(data & ALIGN_MASK) >> 15], (data & BOLD_MASK) >> 17 ? "on" : "off",
			(data & ITALIC_MASK) >> 18 ? "on" : "off", (data & UNDERLINE_MASK) >> 19 ? "on" : "off");
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
				data &= ~ID_MASK;
				data |= input;
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
				data &= ~SZ_MASK;
				data |= (input << 8);
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
				data &= ~ALIGN_MASK;
				data |= (input << 15);
				break;
			case 'b':
				data ^= BOLD_MASK; 
				break;
			case 'i':
				data ^= ITALIC_MASK;;
				break;
			case 'u':
				data ^= UNDERLINE_MASK;;
				break;
		}
		printf("ID      SIZE    ALIGNMENT       B       I       U       \n"
				"%-5u%6u%12s%12s%7s%7s\n", data & ID_MASK, (data & SZ_MASK) >> 8, aligns[(data & ALIGN_MASK) >> 15],
				(data & BOLD_MASK) >> 17 ? "on" : "off", (data & ITALIC_MASK) >> 18 ? "on" : "off", (data & UNDERLINE_MASK) >> 19 ? "on" : "off");
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
