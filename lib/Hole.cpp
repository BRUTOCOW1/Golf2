#include <stdlib.h>
#include <iostream>
#include <string>
#include "Utils.hpp"
#include "Club.cpp"
#include "Shot.cpp"

class Hole {
     public:



        
        Hole(int number);

        void play();





    protected:

        std::string name;
        int par;
        int distance;

        std::vector<Shot> shots;

        bool ballInHole;
        
};

Hole::Hole(int number)
    :name(std::to_string(number)),
    par(intIn("par")),
    distance(intIn("distance")),
    ballInHole(false)
{
}

void Hole::play(){
    while (!ballInHole)
    {
        Shot a;
        a.hit();
        shots.push_back(a);
    }     
}