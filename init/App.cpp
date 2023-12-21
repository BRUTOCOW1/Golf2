#include <stdlib.h>
#include <iostream>
#include <string> 
#include "../lib/Round.cpp"
#include "../lib/Utils.hpp"

using namespace std;

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
    Round round;
    std::string buffer;

    buffer = strIn("to begin your round");
    if (buffer != "tits")
    {
        round.start();
    }

}

int main(){
   GolfDataFactory theFact;
   return 1;
}