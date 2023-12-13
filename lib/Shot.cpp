#include <stdlib.h>
#include <iostream>
#include <ostream>




class Shot {

    enum Direction {Hook, Draw, Straight, Fade, Slice};
    enum Type {Tee, Fairway, Rough, Approach, Pitch, Chip, Putt};

    public:

    Shot(Direction direction, Type type, int distance);


    std::string operator<<(Shot s){
        return "";
    }




    protected:

        


        Direction direction;
        Type type;
        int distance;

};




Shot::Shot(Direction direction, Type type, int distance)
    : direction(direction), type(type), distance(distance)
{
    std::cout << "Hey idiot";
}


