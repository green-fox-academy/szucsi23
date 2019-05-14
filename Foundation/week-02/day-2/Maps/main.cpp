#include <iostream>
#include <map>

int main() {

    //Create an empty map where the keys are integers and the values are characters
    std::map<int, char> cucc;

    //Print out whether the map is empty or not
    std::cout << "This map is ";
    if (cucc.empty() == 0) {
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


    for (it = cucc.begin(); it != cucc.end(); ++it) {
        std::cout << it->first << " ";
    }
    std::cout << std::endl;
    //Print all the values
    for (it = cucc.begin(); it != cucc.end(); ++it) {
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
    if (it == cucc.end()) {
        std::cout << "no ";
    } else {
        std::cout << "a ";
    }
    std::cout << "value associated with the key 100." << std::endl;
    //Remove all the key-value pairs
    cucc.clear();

    std::cout << std::endl;
    //------------------------------------------------------------------------------------------------------------------

    //Create a map where the keys are strings and the values are strings with the following initial values
    std::map<std::string, std::string> map;
    map = {
            {"978-1-60309-452-8", "A Letter to Jo"},
            {"978-1-60309-459-7", "Lupus"},
            {"978-1-60309-444-3", "Red Panda and Moon Bear"},
            {"978-1-60309-461-0", "The Lab"}
    };
    std::map<std::string, std::string>::iterator iter;
    iter = map.begin();

    //Print all the key-value pairs in the following format

    for (iter = map.begin(); iter != map.end() ; iter++) {
        std::cout << iter->second << " (ISBN: " << iter->first << ")" << std::endl;
    }

    //Remove the key-value pair with key 978-1-60309-444-3
    map.erase("978-1-60309-444-3");
    //Remove the key-value pair with value The Lab
    for (iter = map.begin(); iter != map.end() ; iter++) {
        if(iter->second == "The Lab") {
            map.erase(iter);
            break;
        }
    }
    //Add the following key-value pairs to the map
    iter = map.begin();
    map.insert(iter, std::pair<std::string, std::string>("978-1-60309-450-4", "They Called Us Enemy"));
    map.insert(iter, std::pair<std::string, std::string>("978-1-60309-453-5", "Why Did We Trust Him?"));

    std::cout << std::endl;
    for (iter = map.begin(); iter != map.end() ; iter++) {
        std::cout << iter->second << " (ISBN: " << iter->first << ")" << std::endl;
    }

   // Print whether there is an associated value with key 478-0-61159-424-8 or not

    std::cout << "There is ";
    iter = map.find("478-0-61159-424-8");
    if (iter == map.end()) {
        std::cout << "no ";
    } else {
        std::cout << "a ";
    }
    std::cout << "value associated with the key 478-0-61159-424-8." << std::endl;

    //Print the value associated with key 978-1-60309-453-5

    iter = map.find("978-1-60309-453-5");
    std::cout << iter->second << std::endl;

    //------------------------------------------------------------------------------------------------------------------



    return 0;
}