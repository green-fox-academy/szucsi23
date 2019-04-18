#include <iostream>
#include "Pirate.h"
#include "Ship.h"
#include "Armada.h"

int main()
{
    srand(time(nullptr));

    //Testing Pirates---------------------------------------------------------------------------------------------------
    Pirate jack;
    Pirate barbarossa;
    jack.brawl(barbarossa);

    //Testing Ships-----------------------------------------------------------------------------------------------------
    Ship blackPearl("Black Pearl");
    blackPearl.fillship();
    std::cout << blackPearl << std::endl;

    Ship fancy("Fancy");
    fancy.fillship();
    std::cout << fancy << std::endl;

    blackPearl.battle(fancy);
    std::cout << blackPearl << std::endl;
    std::cout << fancy << std::endl;

    //Testing Armada----------------------------------------------------------------------------------------------------
    Armada confederationSpaceNavy;
    confederationSpaceNavy.formAFleet();

    Armada revolutionStarFlotilla;
    revolutionStarFlotilla.formAFleet();

    if (confederationSpaceNavy.war(revolutionStarFlotilla)) {
        std::cout << "The winner is the Confederation Space Navy." << std::endl;
    } else {
        std::cout << "The winner is the Revolution Star Flotilla." << std::endl;
    }

    return 0;
}