//
// Created by hun46 on 2019. 04. 25..
//

#ifndef COWBULL_COWBULL_H
#define COWBULL_COWBULL_H


#include <iostream>
#include <cstdlib>
#include <ctime>

enum GameState {
    RUNNING,
    FINISHED

};

struct Core{
    GameState state = RUNNING;
    char guess[4];
    char secret[4];

};

Core setup(Core);
Core check(Core);
void guessing(char guess[]);

GameState game();


#endif //COWBULL_COWBULL_H
