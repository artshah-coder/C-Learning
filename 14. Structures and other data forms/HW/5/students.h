// заголовочный файл с описанием структур, прототипов функций и констант, используемых в программе
#define NL 20
#define SL 20
#define GRADES 3
#define CSIZE 4

typedef struct{
	char name [NL];		// имя
	char surname [SL];	// фамилия
}NAME;

typedef struct{
	NAME name;		// вложенная структура, хранящая имя и фамилию
	float grade[GRADES];	// массив со значениями оценок студента
	float average;		// среднее значение оценок
}STUDENT;


void eatline (void);			// чистит поток stdin от ненужных символов
int setgrades (STUDENT *, int);		// функция выбора студента и выставления ему оценок,
					//возвращает позицию студнта в массиве
void setavg (STUDENT *);		// функция вычисляет среднюю оценку студента
void printinfo (STUDENT *);		// печать содержимого структуры
float grdavg (STUDENT *, int);		// функция вычисляет среднюю оценку по курсу
