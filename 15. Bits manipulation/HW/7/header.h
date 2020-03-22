#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
// МАСКИ ДЛЯ ИЗВЛЕЧЕНИЯ ЗНАЧЕНИЙ ИЗ ПАМЯТИ
#define ID_MASK 0xFF
#define SZ_MASK 0x7F00
#define ALIGN_MASK 0x18000
#define BOLD_MASK 0x20000
#define ITALIC_MASK 0x40000
#define UNDERLINE_MASK 0x80000 

static char * aligns [3] = {"left", "center", "right"};
void eatline(void);
