#include <stdlib.h>
#include <iostream>

std::string getInput(std::string info){
        std::cout << "Please Enter " << info << std::endl << "-> ";
        std::string ret;
        getline(std::cin, ret);
        return ret;
}
