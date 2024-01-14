#include <stdlib.h>
#include <iostream>
#include <string> 
#include "GDBI.hpp"
#include "../lib/Course.hpp"
#include "../lib/Round.cpp"

using namespace std;

std::string getInput()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

class GolfDataFactory {
    public:
        GolfDataFactory();
    
    protected:

        bool initialize();
        void process();
    
};

GolfDataFactory::GolfDataFactory()
   
{
    if (!initialize()){
        std::cout << "Failed In Initialization";
        return;
    }
    process();
}

bool GolfDataFactory::initialize(){
    return true;
}

void GolfDataFactory::process(){
    std::string userIn{getInput()};
    if (userIn == "round")
    {
        Round round;
        std::string buffer;

        buffer = strIn("to begin your round");
        if (buffer != "tits")
        {
            round.start();
        }
    } else {
        GDBI gdbi;
        CourseBuilder cb;
    }
   

}

int main(){
   GolfDataFactory theFact;
   return 1;
}

