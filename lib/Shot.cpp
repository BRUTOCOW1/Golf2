#include <stdlib.h>
#include <iostream>
#include <ostream>


class Shot {

    public:

    Shot();

    void hit();

    bool isMake();

    protected:

        Club c;
        ShotDirection direction;
        ShotType type;
        int distance;

        bool made;


};

Shot::Shot()
    :  type(shotTypes[strInLow("Shot Type")]), made(false)
{
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
