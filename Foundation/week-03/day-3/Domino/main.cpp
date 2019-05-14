#include <iostream>
#include <vector>

#include "domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    std::vector<Domino>::iterator iterator = dominoes.begin();

    std::vector<Domino> line;
    line.push_back(*iterator);

    for(int i = 0; i < dominoes.size(); i++){

        std::pair<int,int> currentpiece = (line.end()-1)->getValues();

        for (iterator = dominoes.begin()+1; iterator < dominoes.end(); iterator++) {
            std::pair<int,int> nextpiece = iterator->getValues();
            if(currentpiece.second == nextpiece.first){
                line.push_back(*iterator);
            }
        }
    }

    iterator = line.begin();
    for (; iterator < line.end(); iterator++) {
        std::cout << iterator->getValues().first << " " << iterator->getValues().second << " | ";
    }


    return 0;
}