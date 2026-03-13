#include <stdio.h>
#include <time.h>
#include "cars.h"

void print_car(const Car *c) {
    printf("Марка: %s, Цвет: %s, Серийный номер: %s, Регномер: %s, Год выпуска: %d, Год техосмотра: %d, Цена: %d\n",
           c->brand, c->color, c->serial_number, c->reg_number, c->year, c->tech_year, c->price);
}

void print_old_cars(const char *input, const char *output) {
    FILE *fin = fopen(input, "r");
    if (!fin) {
        printf("Не удалось открыть файл %s\n", input);
        return;
    }

    FILE *fout = fopen(output, "w");
    if (!fout) {
        printf("Не удалось создать файл %s\n", output);
        fclose(fin);
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int current_year = tm.tm_year + 1900;

    Car c;
    int count_read = 0;
    int count_old = 0;

    printf("Исходные данные из файла %s:\n", input);
    while (fscanf(fin, "%s %s %s %s %d %d %d",
                  c.brand, c.color, c.serial_number, c.reg_number,
                  &c.year, &c.tech_year, &c.price) == 7)
    {
        count_read++;
        print_car(&c);

        if (current_year - c.year > 2) {
            fprintf(fout, "%s %s %s %s %d %d %d\n",
                    c.brand, c.color, c.serial_number, c.reg_number,
                    c.year, c.tech_year, c.price);
            count_old++;
        }
    }

    printf("\nВсего прочитано: %d\n", count_read);
    printf("Автомобилей старше 2 лет: %d (результат сохранён в %s)\n", count_old, output);

    fclose(fin);
    fclose(fout);
}
