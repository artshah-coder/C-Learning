/* fields.c -- определение и использование полей */
#include<stdio.h>
#include<stdbool.h>	// C99, определение bool, true, false
/* стили линии */
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/* основные цвета */
#define BLUE 4
#define GREEN 2
#define RED 1
/* смешанные цвета */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"черный", "красный", "зеленый", "желтый",
	"синий", "пурпурный", "голубой", "белый"};

struct box_props {
	bool opaque			: 1;	// или unsigned int (до C99)
	unsigned int fill_color		: 3;
	unsigned int			: 4;
	bool show_border		: 1;	// или unsigned int (до C99)
	unsigned int border_style	: 2;
	unsigned int border_color	: 3;
	unsigned int			: 2;	
};

void show_settings(const struct box_props * pb);

int main (void)
{
	/* создание и инициализация структуры box_props */
	struct box_props box = {true, YELLOW, true, GREEN, DASHED};
	printf("Исходные настройки окна:\n");
	show_settings(&box);
	box.opaque = false;
	box.fill_color = WHITE;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf("\nИзмененные настройки окна:\n");
	show_settings(&box);

	return 0;
}

void show_settings(const struct box_props * pb)
{
	printf("Окно %s.\n",
			pb->opaque ? "непрозрачно": "прозрачно");
	printf("Цвет фона %s.\n", colors[pb->fill_color]);
	printf("Рамка %s.\n", pb->show_border ? "отображается" : "не отображается");
	printf("Цвет рамки %s.\n", colors[pb->border_color]);
	printf("Стиль рамки ");
	switch (pb->border_style)
	{
		case SOLID: printf("сплошной.\n"); break;
		case DASHED: printf("штрихованный.\n"); break;
		case DOTTED: printf("пунктирный.\n"); break;
		default: printf("неизвестный.\n"); break;
	}
}
