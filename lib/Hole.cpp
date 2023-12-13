#include <stdlib.h>
#include <iostream>
#include <string>
#include "Shot.cpp"

class Hole {
     public:



        enum TTG { TTGSTRAIGHT, RIGHT, LEFT};
        enum Shape { STRAIGHT, DOGLEG };
        enum Topo {FLAT, UP, DOWN};
        enum Hazards {WATER, GREENSIDEBUNKER, FAIRWAYBUNKER};
        enum Obstructions {TREE, BLIND};
        
        Hole(int number, int par, int distance, Shape shape);


    protected:

        std::string name;
        int par;
        std::vector<Shot> shots;
        
};

Hole::Hole(int number, int par, int distance, Shape shape)
    :name(std::to_string(number)), par(par)
{
    std::cout << "What foin down";
}

