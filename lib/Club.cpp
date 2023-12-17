#include <stdlib.h>
#include <iostream>
#include <map>
#include "Utils.hpp"



class Club {
    public:
        std::string name;
        Club();

        void stringToClub(std::string str);

    protected:


        ClubMake make;
        ClubModel model;

};

Club::Club()
{
    stringToClub(strIn("Club (Make and Model)"));
}

void Club::stringToClub(std::string dir){
    auto split = simple_tokenizer(dir);
    make = clubMakes[split[0]];
    model = clubModels[split[1]];
}

