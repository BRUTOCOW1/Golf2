#include <stdlib.h>
#include <iostream>
#include <string> 
#include <vector>
#include "Utils.cpp"
#include "Hole.cpp"

class Course {
    public:


        Course();

        void printCourse();


    protected:

        std::string name;
        int par;
        std::vector<Hole> holes;
};

void Course::printCourse(){
    std::cout << "Course name: " << name << std::endl;
    std::cout << "Course par: " << par << std::endl;
}



Course::Course() : name(getInput("Course Name")), par(stoi(getInput("Par"))) {}
