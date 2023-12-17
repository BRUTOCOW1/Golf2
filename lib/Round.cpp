#include <stdlib.h>
#include <iostream>
#include "Course.cpp"
#include "Golfer.cpp"
#include "Utils.hpp"


class Round {
    public:

        Golfer golfer;
        
        Course course;

        Round();

        

        void start();

        void playHole(int holeNum);






    protected:
        std::vector<int> scoreCard;
        std::vector<Hole> holes;
        int numHoles;

        int score;

};

Round::Round()
    :score(0), numHoles(intIn("number of holes"))
{
    popAllOpts();
}

void Round::start(){
    for (int i = 0; i < numHoles; i++) {
        playHole(i);
    }

}

void Round::playHole(int holeNum){
    Hole h(holeNum);
    h.play();
    holes.push_back(h);
}