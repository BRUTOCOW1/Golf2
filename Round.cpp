#include <stdlib.h>
#include <iostream>
#include "Shot.cpp"

class Club {
    public:
        std::string name;
        int totalShotsHit;
        float averageDistance;




    protected:

        void logShot(Shot shot) {
            totalShotsHit++;
            calcAverage(shot.distance);
        }

        void calcAverage(int distance){ 
            averageDistance += distance/totalShotsHit;
        }

};

