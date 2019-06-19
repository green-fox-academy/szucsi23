//
// Created by hun46 on 2019. 06. 06..
//

#ifndef BUS_BUS_H
#define BUS_BUS_H

typedef struct {
    char name[30];
    int seats;
    int standing_places;
    int passengers;
} bus_t;

void read_from_file(char*);

#endif //BUS_BUS_H
