#include <iostream>
#include <map>

int main() {

    std::map<std::string, std::string> phonebook;
    phonebook = {
            {"William A. Lathan",   "405-709-1865"},
            {"John K. Miller",      "402-247-8568"},
            {"Hortensia E. Foster", "606-481-6467"},
            {"Amanda D. Newland",   "319-243-5613"},
            {"Brooke P. Askew",     "307-687-2982"},
    };

    //What is John K. Miller's phone number?
    std::map<std::string, std::string>::iterator it = phonebook.begin();
    it = phonebook.find("John K. Miller");
    std::cout << it->second << std::endl;

    //Whose phone number is 307-687-2982?
    for (it = phonebook.begin(); it != phonebook.end(); ++it) {
        if (it->second == "307-687-2982") {
            std::cout << it->first;
        }
    }
    std::cout << std::endl;
    //Do we know Chris E. Myers' phone number?
    //no.

    if (phonebook.end() == phonebook.find("Chris E. Myers")) {
        std::cout << "nope" << std::endl;
    }

    //------------------------------------------------------------------------------------------------------------------

    std::map<std::string, int> products;
    products = {
            {"Eggs",    200},
            {"Milk",    200},
            {"Fish",    400},
            {"Apples",  150},
            {"Bread",   50},
            {"Chicken", 550}
    };

    std::map<std::string, int>::iterator iter;

    // How much is the fish?
    std::cout << std::endl;
    iter = products.find("Fish");
    std::cout << iter->second << std::endl;

    // What is the most expensive product?
    std::cout << std::endl;
    int max = iter->second;
    int sum = 0;
    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second > max) {
            max = iter->second;
        }
        sum += iter->second;
    }
    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second == max) {
            std::cout << iter->first << std::endl;
        }
    }
    // What is the average price?
    std::cout << std::endl;
    int avg = sum/products.size();
    // How many products' price is below 300?
    std::cout << std::endl;
    int below = 0;
    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second < 300) {
            below++;
        }
    }
    // Is there anything we can buy for exactly 125?
    std::cout << std::endl;
    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second == 125) {
            std::cout << iter->first << std::endl;
        }
    }
    // What is the cheapest product?
    std::cout << std::endl;
    iter = products.begin();
    int min = iter->second;

    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second < min) {
            min = iter->second;
        }
    }
    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second == min) {
            std::cout << iter->first << std::endl;
        }
    }
    //Which products cost less than 201? (just the name)
    std::cout << std::endl;
    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second < 201) {
            std::cout << iter->first << std::endl;
        }
    }
    //Which products cost more than 150? (name + price)
    std::cout << std::endl;
    for (iter = products.begin(); iter != products.end(); iter++) {
        if (iter->second > 150) {
            std::cout << iter->first << " " << iter->second<< std::endl;
        }
    }

    return 0;
}