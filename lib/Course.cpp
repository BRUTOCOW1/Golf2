#include <stdlib.h>
#include <iostream>
#include <string> 
#include <vector>
#include "Utils.hpp"
#include "Hole.cpp"

class Course {
    public:

        Course();        

    protected:

        std::string name;
        int par;
        std::vector<Hole> holes;
};

Course::Course() 
    : name(strIn("Course Name")), par(intIn("Par"))
{
}
