#include <stdio.h>
#include <string.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct {
    char address[50];
    int price;
    int num_of_rooms;
    int area;
} house_t;

int does_it_worth_it(house_t*);
int count_worthy(house_t houses[], int size);

int main()
{
    house_t houses[3];

    strcpy(houses[0].address, "This address");
    houses[0].area = 100;
    houses[0].price = 10000;
    houses[0].num_of_rooms = 3;

    strcpy(houses[1].address, "That address");
    houses[1].area = 100;
    houses[1].price = 40000;
    houses[1].num_of_rooms = 3;

    strcpy(houses[2].address, "Other address");
    houses[2].area = 100;
    houses[2].price = 90000;
    houses[2].num_of_rooms = 3;

    int size = sizeof(houses)/ sizeof(house_t);

    printf("%d", count_worthy(houses, size));

    return 0;
}

int does_it_worth_it(house_t *house)
{
    return(house->price <= (house->area*400));
}

int count_worthy(house_t *houses, int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if(does_it_worth_it(&houses[i])) {
            counter++;
        }
    }
    return counter;
}
