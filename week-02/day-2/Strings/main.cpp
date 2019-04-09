#include <iostream>
#include <string>

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

    

    return 0;
}