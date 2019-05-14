#include <iostream>
#include "Garden.h"
#include "Flower.h"
#include "Tree.h"

int main()
{
    Garden myGarden;
    Flower yellow("yellow", FLOWER, 0);
    Flower blue("blue", FLOWER, 0);
    Tree purple("purple", TREE, 0);
    Tree orange("orange", TREE, 0);

    myGarden.add(&yellow);
    myGarden.add(&blue);
    myGarden.add(&purple);
    myGarden.add(&orange);

    myGarden.watering(0);
    std::cout << std::endl;
    myGarden.watering(40);
    std::cout << std::endl;
    myGarden.watering(70);



/*The yellow Flower needs water
The blue Flower needs water
The purple Tree needs water
The orange Tree needs water*/

    return 0;
}