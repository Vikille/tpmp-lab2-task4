#ifndef CARS_H
#define CARS_H

#define MAX_BRAND 50
#define MAX_COLOR 30
#define MAX_REGNUM 20

typedef struct {
    char brand[MAX_BRAND];
    char color[MAX_COLOR];
    char serial_number[20];
    char reg_number[MAX_REGNUM];
    int year;
    int tech_year;
    int price;
} Car;

void print_car(const Car *c);
void print_old_cars(const char *input, const char *output);

#endif
