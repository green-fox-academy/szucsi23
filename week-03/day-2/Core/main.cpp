
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copy(std::string, std::string);

void ids(std::string, std::vector<std::string>&);
double ratio(std::string);


int main()
{

    // Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
    // It should take the filenames as parameters
    // It should return a boolean that shows if the copy was successful

    std::string from = "..//from.txt";
    std::string to = "..//to.txt";

    if (copy(from, to)) {
        std::cout << "All good." << std::endl;
    } else {
        std::cout << "Copy didn't hapen." << std::endl;
    }

    //------------------------------------------------------------------------------------------------------------------

    // Read all data from 'log.txt'.
    // Each line represents a log message from a web server
    // Write a function that returns an array with the unique IP adresses.
    // Write a function that returns the GET / POST request ratio.

    std::string name = "..//log.txt";
    std::vector<std::string> array;
    ids(name, array);
    std::vector<std::string>::iterator iter = array.begin();
    for (; iter != array.end(); ++iter) {
        std::cout <<*iter << std::endl;
    }


    double rate = ratio(name);
    std::cout << std::endl << rate << std::endl;
    return 0;
}

bool copy(std::string fname1, std::string fname2)
{
    std::ifstream read;
    std::ofstream write;

    write.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        read.open(fname1);
        write.open(fname2);

        std::string str;
        while (getline(read, str)) {
            write << str << std::endl;
        }
    } catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}

void ids(std::string name, std::vector<std::string> &array)
{
    std::ifstream logfile(name);
    std::string line;

    int counter = 0;
    while (std::getline(logfile, line)) {
        std::istringstream ss(line);
        std::string token;

        counter = 0;
        while (std::getline(ss, token, ' ')) {
            //std::cout << token << " ";
            counter++;
            if(counter == 9) {
                array.push_back(token);
            }
        }
        //std::cout << std::endl;
    }
}

double ratio(std::string name)
{
    std::ifstream logfile(name);
    std::string line;
    int gets = 0;
    int posts = 0;

    int counter = 0;
    while (std::getline(logfile, line)) {
        std::istringstream ss(line);
        std::string token;

        counter = 0;
        while (std::getline(ss, token, ' ')) {
            //std::cout << token << " ";
            counter++;
            if(counter == 12) {
                if (token == "POST") posts++;
                if (token == "GET") gets++;
            }
        }
        //std::cout << std::endl;
    }
    return ((double)gets/posts);
}
