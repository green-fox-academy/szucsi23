#include <iostream>
#include <vector>

int main() {

    // Create an empty list which will contain names (strings)
    std::vector<std::string> v;
    // Print out the number of elements in the list
    for (std::string n : v) {
        std::cout << n << std::endl;
    }
    // Add William to the list
    v.push_back("William");
    // Print out whether the list is empty or not
    std::cout << "This list is empty, and this statement is " << v.empty() << "." << std::endl;
    // Add John to the list
    v.push_back("John");
    // Add Amanda to the list
    v.push_back("Amanda");
    // Print out the number of elements in the list
    std::cout << v.size() << std::endl;
    // Print out the 3rd element
    std::cout << v.at(2) << std::endl;
    // Iterate through the list and print out each name
    for (std::string n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    //Iterate through the list and print
    for (unsigned int i = 0; i < v.size(); i++) {
        std::cout << i + 1 << " " << v.at(i) << std::endl;
    }
    //Remove the 2nd element
    v.erase(v.begin() + 1);
    //Iterate through the list in a reversed order and print out each name
    for (unsigned int i = v.size(); i > 0; i--) {
        std::cout << v.at(i - 1) << std::endl;

    }
    v.clear();
    std::cout << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    std::vector<int> expanses = {500, 1000, 1250, 175, 800, 120};
    //Create an application which solves the following problems.
    //How much did we spend?
    int sum = 0;
    for (unsigned int j = 0; j < expanses.size(); ++j) {
        sum += expanses.at(j);
    }
    //Which was our greatest expense?
    int max = expanses[0];
    for (unsigned int j = 0; j < expanses.size(); ++j) {
        if (max < expanses.at(j)) {
            max = expanses.at(j);
        }
    }
    //Which was our cheapest spending?
    int min = expanses[0];
    std::vector<int>::iterator it;
    for (it = expanses.begin(); it != expanses.end(); it++) {
        if(min > *it) {
            min = *it;
        }
    }
    //What was the average amount of our spendings?
    int avg = sum/(expanses.size());

    for (int m : expanses) {
        std::cout << m << " ";
    }
    std::cout << std::endl;
    std::cout << sum << " " << max << " " << min << " " << avg << std::endl;
    return 0;
}