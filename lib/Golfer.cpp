#include <stdlib.h>
#include <iostream>

class Golfer {
    public:
        std::string fName;
        std::string lName;
        int roundsPlayed;

        Golfer();





    protected:

      
};

Golfer::Golfer()
{
    std::cout << "Hello, please enter your first and last name" << std::endl << "-> ";
    std::string testString;
    getline(std::cin, testString);
    fName = testString;
}

