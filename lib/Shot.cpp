#include <stdlib.h>
#include <iostream>
#include <ostream>
#include "Lie.cpp"

class Shot {

    public:

        Shot();

        void hit();

        bool isMake();

    protected:
        ShotType type;
        Club c;
        Lie lie;
        ShotDirection direction;
        
        int distance;

        bool made;


};

Shot::Shot()
    :  type(shotTypes[strInLow("Shot Type")]), made(false)
{
    lie.eval(type);

}

void Shot::hit(){
    if (type == ShotType::PUTT)
    {
        if (strIn("Did it go in?") == "yes")
        {
            made = true;
            return;
        }
    }
    distance = intIn("how far the ball went");
    direction = shotDirections[strInLow("Direction")];

    auto glance = intIn("Distance to hole");
    if (glance <= 0) made = true;

}

bool Shot::isMake(){
    return made;
}
