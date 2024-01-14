#include <stdlib.h>
#include <iostream>
#include <string>
#include "Club.cpp"
#include "Shot.cpp"
#include "Utils.hpp"

class Hole {
     public:

        Hole(int number);

        void play();

        int getScore() {return score;}
        int getPar() {return par;}

    protected:

        std::string name;
        int par;
        int distance;

        std::vector<Shot> shots;

        bool ballInHole;

        int score;

        Score deduceScore();
        
};

Hole::Hole(int number)
    :name(std::to_string(number)),
    par(intIn("par")),
    distance(intIn("distance")),
    ballInHole(false),
    score(0)
{
}

void Hole::play(){
    std::cout << "It is a " << distance << " yard par " << par << std::endl;
    while (!ballInHole)
    {
        Shot a;
        a.hit();
        score++;
        shots.push_back(a);

        if (a.isMake())
        {
            ballInHole = true;
        }
    }  
    deduceScore();   
}

Score Hole::deduceScore(){

    int hP {0};
    switch(par){
        case 4: hP = 1; break;
        case 5: hP = 2; break;
    }
    int fScore = score-hP;

    Score inWith = static_cast<Score>(fScore);

    std::cout << "You shot a " << score << " on a par " << par << std::endl;
    std::cout << "Congrats on your " << scoreNames[fScore] << std::endl;

    return inWith;
}