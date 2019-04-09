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

    //------------------------------------------------------------------------------------------------------------------


    //Create a list ('List A') which contains the following values
    //Apple, Avocado, Blueberries, Durian, Lychee
    std::vector<std::string> A = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};

    //Create a new list ('List B') with the values of List A
    std::vector<std::string> B = A;

    //Print out whether List A contains Durian or not
    bool flag = true;

    std::cout << "The list A does ";
    for (int k = 0; k < A.size(); ++k) {
        if(A.at(k) == "Durian") {
            flag = false;
        }
    }
    if(flag) std::cout << "not ";
    std::cout << "contain Durian." << std::endl;
    //        Remove Durian from List B

    std::vector<std::string>::iterator iter;
    for (iter = B.begin(); iter < B.end(); ++iter) {
        if(*iter == "Durian") {
            B.erase(iter);
        }
    }
    //Add Kiwifruit to List A after the 4th element
    iter = A.begin()+4;
    A.insert(iter, "Kiwifruit");
    //Compare the size of List A and List B
    
    //Get the index of Avocado from List A
    //Get the index of Durian from List B
    //Add Passion Fruit and Pummelo to List B in a single statement
    //Print out the 3rd element from List A



    return 0;
}