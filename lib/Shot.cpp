#include <stdlib.h>
#include <iostream>
#include <ostream>


class Shot {

    public:

    Shot();

    void hit();

    protected:

        Club c;
        ShotDirection direction;
        ShotType type;
        int distance;


};


Shot::Shot()
    : direction(shotDirections[strIn("Direction")]), type(shotTypes[strIn("type")]), distance(intIn("distance"))
{
}

void Shot::hit(){
    distance = intIn("how far the ball went");

}
