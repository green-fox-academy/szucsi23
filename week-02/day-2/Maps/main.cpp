#include <iostream>
#include <map>

int main() {

    //Create an empty map where the keys are integers and the values are characters
    std::map<int,char> cucc;

    //Print out whether the map is empty or not
    std::cout << "This map is ";
    if(cucc.empty() == 0) {
        std::cout << "not ";
    }
    std::cout << "empty." << std::endl;

    //Add the following key-value pairs to the map
    std::map<int, char>::iterator it = cucc.begin();
    cucc = {
            {97, 'a'},
            {98, 'b'},
            {99, 'c'},
            {65, 'A'},
            {66, 'B'},
            {67, 'C'}
    };
    //Print all the keys


    for (it=cucc.begin(); it != cucc.end(); ++it) {
        std::cout << it->first << " ";
    }
    std::cout << std::endl;
    //Print all the values
    for (it=cucc.begin(); it != cucc.end(); ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    //Add value D with the key 68
    cucc.insert(it, std::pair<int, char>(68, 'D'));

    //Print how many key-value pairs are in the map
    std::cout << cucc.size() << std::endl;
    //Print the value that is associated with key 99
    it = cucc.find(99);
    std::cout << it->second << std::endl;
    //Remove the key-value pair where with key 97
    cucc.erase(97);
    //Print whether there is an associated value with key 100 or not
    std::cout << "There is ";
    it = cucc.find(100);
    if(it == cucc.end()) {
        std::cout << "no ";
    } else {
        std::cout << "a ";
    }
    std::cout << "value associated with the key 100." << std::endl;
    //Remove all the key-value pairs
    cucc.clear();
    return 0;
}