#include <iostream>
#include <string>

std::string reverse(std::string str);

int main() {

    std::string example("In a dishwasher far far away");
    example.replace(5, 10, "galaxy");

    // I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
    // Please fix it for me!
    // Expected output: In a galaxy far far away

    std::cout << example << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    std::string url("https//www.reddit.com/r/nevertellmethebots");

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it too!

    int pos = 0;
    pos = url.find("bots");
    url.replace(pos, 4, "odds/");

    std::cout << url << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");

    // When saving this quote a disk error has occured. Please fix it.
    // Add "always takes longer than" to the quote between the words "It" and "you" using the replace function

    int pos1 = quote.find("It") + 3;
    int pos2 = quote.find("you");


    quote.replace(pos1, 0, "always takes longer than ");


    std::cout << quote << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    std::string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";

    // Create a method that can reverse an std:string, which is passed as the parameter
    // Use it on this reversed string to check it!
    // Try to solve this using .at() first, and optionally anything else after.
    // Hint: You might use a temporary variable to swap 2 characters or you can use std::swap function.

    std::cout << reverse(reversed) << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    return 0;
}

std::string reverse(std::string str) {
    int size = str.length();
    std::string swapped = "";

    for (int i = 0; i < size; ++i) {
        swapped += str.at(size-i-1);

    }

    return swapped;
}