#include <stdlib.h>
#include <iostream>
#include <ostream>




class Shot {

    enum Direction {Hook, Draw, Straight, Fade, Slice};
    enum Type {Tee, Fairway, Rough, Approach, Pitch, Chip, Putt};

    public:

    void logShot(Shot shot) {
        std::cout << ":)";
    }

    std::string operator<<(Shot s){
        return "";
    }

    int getDistance() {
        return distance;
    }


    protected:

        


        Direction direction;
        Type type;
        int distance;

};


