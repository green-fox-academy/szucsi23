#include <iostream>
#include "Birds.h"
#include "Mammals.h"
#include "Reptiles.h"

int main( int argc, char* args[] )
{
    Reptiles reptile("Crocodile");
    Mammals mammal("Koala");
    Birds bird("Parrot");

    std::cout << "How do you breed?" << std::endl;
    std::cout << "A " << reptile.getname() << " is breeding by " << reptile.breed() << "." << std::endl;
    std::cout << "A " << mammal.getname() << " is breeding by " << mammal.breed() << "." <<  std::endl;
    std::cout << "A " << bird.getname() << " is breeding by " << bird.breed() << "." <<  std::endl;
}