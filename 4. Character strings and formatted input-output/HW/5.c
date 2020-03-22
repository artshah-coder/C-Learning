// Упр. 5, стр. 155
#include<stdio.h>

int main(void)
{
	float speed, size;
	printf("Введите скорость загрузки в Мбит/с и размер файла, МБ:\n");
	scanf("%f %f", &speed, &size);
	printf("При скорости загрузки %.2f Мбит/с файл размером %.2f будет скачиваться за %.2f секунд(-ы)\n", speed, size, size*8/speed);

	return 0;
}
