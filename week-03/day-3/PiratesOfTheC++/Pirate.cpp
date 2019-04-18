//
// Created by hun46 on 2019. 04. 17..
//

#include "Pirate.h"
#include <iostream>
#include <time.h>

Pirate::Pirate(int drunkness, int hp, bool parrot)
{
    this->drunkness = drunkness;
    this->hp = hp;
    this->parrot = parrot;
}

void Pirate::drinkSomeRum()
{
    if (this->hp > 10) {
        this->drunkness++;
        if(drunkness > 4) this->passOut();

    } else if (this->hp > 0){
        std::cout << "/He's passed out./" << std::endl;

    } else {
        std::cout << "/He's sleeping with the fishes./" << std::endl;
    }
}

void Pirate::howsItGoingMate()
{
    if (!this->dead) {
        if (this->drunkness <= 4) {

            if(passedOut){
                this->passedOut = false;
                this->hp = 50;
            }

            std::cout << "-Pour me anudder!" << std::endl;
            this->hp += 10;

        } else {
            std::cout << "-Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
            this->passOut();
            this->drunkness = 0;
        }
    } else {
        std::cout << "/He's dead./" << std::endl;
    }
}

void Pirate::die()
{
    this->hp = 0;
    this->passedOut = false;
    this->dead = true;
}

void Pirate::passOut()
{
    this->hp = 5;
    this->passedOut = true;
}

void Pirate::brawl(Pirate other)
{
    if (!other.dead && !other.passedOut) {

        int outcome = (rand() % 30) + 1;

        if (this->parrot) {
            outcome += 3;
        }

        if(0 <= outcome && outcome <= 10){
            this->die();
            std::cout << "-Arggh, this wasnt a good idea." << std::endl;

        }else if(10 < outcome && outcome <= 20){
            this->passOut();
            other.passOut();
            std::cout << "-Fair fight, brother!" << std::endl;

        } else if(20 < outcome) {
            other.die();
            std::cout << "-Ima wee tough bastard!" << std::endl;
        }

    } else {
        std::cout << "/The other pirate is dead or passed out./" << std::endl;
    }
}

int Pirate::getDrunkness() const
{
    return drunkness;
}

int Pirate::getHp() const
{
    return hp;
}

bool Pirate::isPassedOut() const
{
    return passedOut;
}

bool Pirate::isDead() const
{
    return dead;
}

