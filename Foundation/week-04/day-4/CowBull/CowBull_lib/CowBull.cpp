//
// Created by hun46 on 2019. 04. 25..
//

#include "CowBull.h"

Core setup(Core core)
{
    for (int i = 0; i < 4; ++i) {

        int dice = rand() % 6 + 1;
        switch (dice) {
            case 1:
                core.secret[i] = 'R';
                break;
            case 2:
                core.secret[i] = 'O';
                break;
            case 3:
                core.secret[i] = 'Y';
                break;
            case 4:
                core.secret[i] = 'G';
                break;
            case 5:
                core.secret[i] = 'B';
                break;
            case 6:
                core.secret[i] = 'V';
                break;
        }
    }

    return core;
}

Core check(Core core) {

    bool Checked[4];
    for (int i = 0; i < 4; i++) Checked[i] = false;
    int cows = 0;
    int bulls = 0;

    for (int i = 0; i < 4; i++) {
        if (core.secret[i] == core.guess[i]) {
            bulls++;
            Checked[i] = true;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (!Checked[i]) {
            if (core.secret[i] == core.guess[0] || core.secret[i] == core.guess[1] ||
                core.secret[i] == core.guess[2] || core.secret[i] == core.guess[3]) {
                cows++;
                Checked[i] = true;
            }
        }
    }

    if (bulls == 4) {
        core.state = FINISHED;
    }
    else {
        std::cout << std::endl;
        std::cout << "You have "<< cows << " Cows, and " << bulls << " Bulls." << std::endl;
        std::cout << std::endl;
        core.state = RUNNING;
    }
    return core;
}

GameState game()
{
    srand(time(NULL));
    Core core;
    int TurnCount = 1;
    core.state = RUNNING;

    std::cout << "Welcome to the Cows and Bulls game!" << std::endl;
    std::cout << std::endl;
    std::cout << "I have four colours for you to find out." << std::endl;
    std::cout << std::endl;
    std::cout << "You can choose from the following: Red, Orange, Yellow, Green, Blue, Violet" << std::endl;
    std::cout << "Use the first letters of the respective colours as indicators. (R, O, Y, G, B, V)" << std::endl;
    std::cout << std::endl;
    std::cout << "If you can find out my secret in less than 10 rounds, you win!" << std::endl;
    std::cout << "Let the game begin!" << std::endl;

    core = setup(core);

    /*//For testing purposes:
    for (int i = 0; i < 4; i++) {
        std::cout << core.secret[i] << " ";
    }*/


    while (core.state == RUNNING) {

        std::cout << std::endl;
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        if (TurnCount < 10) {
            std::cout << "You are in the " << TurnCount << ". turn." << std::endl;
        }
        else {
            std::cout << "You are in the LAST turn." << std::endl;
        }

        guessing(core.guess);
        core = check(core);

        if(core.state == FINISHED) {
            std::cout << std::endl;
            std::cout << "********************************" << std::endl;
            std::cout << "*       Congratulations!       *" << std::endl;
            std::cout << "********************************" << std::endl;
        }

        TurnCount++;
        if (TurnCount > 10 && core.state != FINISHED) {
            std::cout << std::endl;
            std::cout << "Sorry, but you have ran out of guesses." << std::endl;
            std::cout << "The combination was: ";
            for (int i = 0; i < 4; i++) {
                std::cout << core.secret[i] << " ";
            }
            std::cout << std::endl;
            core.state = FINISHED;
        }

    }

    std::cout << std::endl;
    std::cout << "Thank you, for playing with me!" << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "..........Press ENTER to exit the program.........." <<std::endl;
    std::cin.get();

    return core.state;
}

void guessing(char guess[])
{
    for (int i = 0; i < 4; i++) {
        std::cout << "Guess for the " << i + 1 << ". colour:";
        std::cin >> guess[i];

        if (guess[i] != 'R' && guess[i] != 'O' && guess[i] != 'Y' && guess[i] != 'G' && guess[i] != 'B' && guess[i] != 'V') {
            std::cout << "Invalid guess. Try again!";
            i--;
        }
    }
}
