#include <stdlib.h>
#include <iostream>
#include "Utils.hpp"

class Golfer {
    public:
        std::string fName;
        std::string lName;

        Golfer();

        void greet();





    protected:

      
};

void Golfer::greet(){
    std::cout << "Welcome, " << fName << "!" << std::endl;
}


Golfer::Golfer()
:fName(strIn("first name")), lName(strIn("last name"))
{
   greet();
}

