
#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {
    VOLVO, TOYOTA, LAND_ROVER, TESLA
};

typedef struct car {
    enum car_type type;
    double km;
    double gas;
} car_t;

void print_info(car_t car);

char *type_to_string(enum car_type type);

        int main()
{
    car_t car;
    car.type = TESLA;
    car.gas = 30;
    car.km = 1000;

    print_info(car);
    return 0;
}

void print_info(car_t car)
{

    printf("%s %.1lf ", type_to_string(car.type), car.km);
    if (car.type != TESLA) printf("%.1lf\n", car.gas);

}

char *type_to_string(enum car_type type)
{
    switch (type){
        case VOLVO : return "Volvo";
        case TOYOTA : return "Toyota";
        case LAND_ROVER : return "Land Rover";
        case TESLA : return "Tesla";

    }
}
