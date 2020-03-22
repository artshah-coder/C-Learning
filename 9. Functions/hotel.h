/* hotel.h -- константы и объявления для программы usehotel.c */
#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.05
#define STARS "*****************************************************************************"

int menu (void); // отображает список отелей для выбора в виде меню

int getnights (void); // возвращает количество суток, на которое бронируется номер

void showprice (double rate, int nights); // вычисляет стоимость в зависимости от отеля и количества суток и выводит результат на экран
