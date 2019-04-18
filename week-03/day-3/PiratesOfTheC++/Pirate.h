//
// Created by hun46 on 2019. 04. 17..
//

#ifndef PIRATESOFTHEC___PIRATE_H
#define PIRATESOFTHEC___PIRATE_H


class Pirate {
public:
    Pirate(int drunkness = 0, int hp = 100, bool parrot = false);

    void drinkSomeRum();
    void howsItGoingMate();
    void die();
    void passOut();
    void brawl(Pirate);

    int getDrunkness() const;

    int getHp() const;

    bool isPassedOut() const;

    bool isDead() const;

private:
    int drunkness;
    int hp;
    bool parrot;
    bool passedOut = false;
    bool dead = false;

};


#endif //PIRATESOFTHEC___PIRATE_H
