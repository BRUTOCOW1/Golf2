#include <stdlib.h>
#include <iostream>
#include <string> 
#include "../lib/Round.cpp"
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
}

int main(){
   GolfDataFactory theFact;
}