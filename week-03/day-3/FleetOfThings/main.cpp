#include <iostream>

#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:

    // 1. [ ] Get milk
    Thing milk("Get milk");
    fleet.add(milk);

    // 2. [ ] Remove the obstacles
    Thing obstacles("Remove the obstacles");
    fleet.add(obstacles);

    // 3. [x] Stand up
    Thing stand("Stand up");
    stand.complete();
    fleet.add(stand);

    // 4. [x] Eat lunch
    Thing eat("Eat lunch");
    eat.complete();
    fleet.add(eat);

    std::cout << fleet.toString() << std::endl;
    return 0;
}