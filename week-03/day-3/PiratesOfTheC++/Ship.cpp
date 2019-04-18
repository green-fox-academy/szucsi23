//
// Created by hun46 on 2019. 04. 18..
//

#include "Ship.h"

Ship::Ship(const std::string &name)
{
    this->name = name;
}

void Ship::fillship()
{
    Pirate cap(0, 100, true);
    this->captain = cap;

    int members = (rand() % 15) + 5;

    for (int i = 0; i < members; ++i) {

        int drunk = (rand() % 3);

        int health = (rand() % 70) + 30;
        Pirate guy(drunk, health);
        this->crew.push_back(guy);
    }
}

std::ostream &operator<<(std::ostream &os, const Ship &ship)
{
    os << std::endl << ship.getName() << " has " << ship.getCrew().size() << " pirates on board." << std::endl;
    os << "The captain is ";
    if (!ship.getCaptain().isDead() && !ship.getCaptain().isPassedOut()) {
        switch (ship.getCaptain().getDrunkness()) {
            case 0:
                os << "sober.";
                break;

            case 1:
                os << "slightly drunk.";
                break;

            case 2:
                os << "drunk.";
                break;

            case 3:
                os << "very drunk.";
                break;
            case 4:
                os << "almost passed out.";
                break;
        }
    } else if (ship.getCaptain().isPassedOut()) {
        os << "passed out.";
    } else {
        os << "dead.";
    }


    return os;
}

void Ship::throwThemOffBoard()
{
    std::vector<Pirate>::iterator iterator = this->crew.begin();
    for (; iterator < this->crew.end(); iterator++) {
        if (iterator->isDead()) {
            crew.erase(iterator);
        }
    }
}

bool Ship::battle(Ship ship)
{
    this->throwThemOffBoard();
    int myScore = calculate(this);

    ship.throwThemOffBoard();
    int theirScore = calculate(&ship);

    Ship *winner;
    Ship *loser;

    if (myScore > theirScore) {
        winner = this;
        loser = &ship;
    } else {
        winner = &ship;
        loser = this;
    }

    std::vector<Pirate>::iterator iterator = winner->crew.begin();

    for (; iterator < winner->crew.end(); iterator++) {

        for (int i = 0; i < (rand() % 3); i++) {
            iterator->drinkSomeRum();
        }
    }

    for (int i = 0; i < ((rand() % 3) + 1); i++) {
        winner->captain.drinkSomeRum();
    }
    iterator = loser->crew.begin();
    for (; iterator < loser->crew.end(); iterator++) {

        if ((rand() % 10) > 4) {
            iterator->die();
        }
    }

    this->throwThemOffBoard();
    ship.throwThemOffBoard();

    std::cout << std::endl << "The winner is: " << winner->name << std::endl;

    if (myScore > theirScore) {
        return true;
    } else {
        return false;
    }
}

int Ship::calculate(Ship *ship)
{
    int score = 0;
    score += ship->crew.size();
    score += ship->captain.getDrunkness();

    return score;
}

const std::vector <Pirate> &Ship::getCrew() const
{
    return crew;
}

const Pirate &Ship::getCaptain() const
{
    return captain;
}

const std::string &Ship::getName() const
{
    return name;
}
