#ifndef COURSE_HPP
#define COURSE_HPP


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



class CourseBuilder {
    public:
        CourseBuilder();
};

#endif // COURSE_HPP
