#include <string.h>
#include <stdio.h>
#include <time.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

typedef enum {
    MANUAL, AUTOMATIC, CVT, SEMI_AUTOMATIC, DUAL_CLUTCH
} transmission_t;

typedef struct {
    char manufactuer[256];
    int price;
    int year_of_manufacture;
    transmission_t transmission;

} car_t;

int get_older_cars_than(car_t *array, int array_length, int age);
int get_transmission_count(car_t *array, int array_length, transmission_t trnsm);

int main()
{
    //túl dekoncentrált vagyok most tesztelni..
    //TODO: add testing
    return 0;
}

int get_older_cars_than(car_t *array, int array_length, int age)
{
    time_t seconds = time(NULL);
    int years = ((((seconds / 60) / 60) / 24) / 365.25);

    int counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (((years + 1970) - array[i].year_of_manufacture) > age) counter++;
    }
    return counter;
}

int get_transmission_count(car_t *array, int array_length, transmission_t trnsm)
{
    int counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (array[i].transmission == trnsm) counter++;
    }
    return counter;
}
