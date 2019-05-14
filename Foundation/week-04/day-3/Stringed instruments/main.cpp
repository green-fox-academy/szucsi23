#include <iostream>
#include "Instrument.h"
#include "StringedInstrument.h"
#include "ElectricGuitar.h"
#include "Violin.h"
#include "BassGuitar.h"


int main(int argc, char* args[] )
{

    std::cout << "\nTest 1, create Electric Guitar, Bass Guitar and Violin with default strings." << std::endl;
    ElectricGuitar guitar;
    BassGuitar bassGuitar;
    Violin violin;

    std::cout<< "\nTest 1 Play" << std::endl;
    guitar.play();
    bassGuitar.play();
    violin.play();

    std::cout << "\nTest 2, create Electric Guitar, Bass Guitar with 30 and 1 strings ." << std::endl;
    ElectricGuitar guitar2(30);
    BassGuitar bassGuitar2(1);

    std::cout << "\nTest 2 Play" << std::endl;
    guitar2.play();
    bassGuitar2.play();

    return 0;
}