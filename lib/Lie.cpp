#include <stdlib.h>
#include <iostream>
#include <ostream>


class Lie {

    public:

    Lie();

    void eval(ShotType type);

    protected:

    LiePlacement liePlace;
    LieLocation lieLoc;

    void gen();
    void evalPutt();


};

Lie::Lie(){}

void Lie::eval(ShotType type)
{
    switch (type){
        case ShotType::TEE : liePlace = LiePlacement::CENTER; lieLoc = LieLocation::TEEBOX; break;
        case ShotType::PUTT : evalPutt(); lieLoc = LieLocation::GREEN; break;
        default : gen(); break;
    }
    
}

void Lie::gen(){
    liePlace = liePlacements[strInLow("Lie Placement ", liePlacementNames)];

}

void Lie::evalPutt(){
}

