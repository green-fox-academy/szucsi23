//
// Created by hun46 on 2019. 04. 18..
//

#ifndef PIRATESOFTHEC___SHIP_H
#define PIRATESOFTHEC___SHIP_H

#include "Pirate.h"
#include <vector>
#include <iostream>
#include <time.h>


class Ship {
public:
    Ship(const std::string &name = "Common Ship");

    void fillship();

    void throwThemOffBoard();

    bool battle(Ship);

    int calculate(Ship *);

    const std::vector<Pirate> &getCrew() const;

    const Pirate &getCaptain() const;

    const std::string &getName() const;

    friend std::ostream &operator<<(std::ostream &os, const Ship &ship);

private:
    std::vector<Pirate> crew;
    Pirate captain;
    std::string name;
};


#endif //PIRATESOFTHEC___SHIP_H
