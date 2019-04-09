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

    if(phonebook.end() == phonebook.find("Chris E. Myers")) {
        std::cout << "nope" << std::endl;
    }



    return 0;
}