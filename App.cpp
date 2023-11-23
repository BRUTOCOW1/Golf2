#include <stdlib.h>
#include <iostream>
#include<string> 
#include "Club.cpp"
#include "Golfer.cpp"
using namespace std;

class GolfDataFactory {
    public:
        GolfDataFactory(){
            start();
        };
    
    protected:
        void start();
        void greet();
    
    

    
};
void GolfDataFactory::start(){
        greet();
    }


void GolfDataFactory::greet(){
        std::string name;
        std::cout << "Hello, please enter your first and last name" << endl << "-> ";
        string testString;
        getline(cin, testString);
        std::cout << " Well, hello there, " << testString;
    }
int main(){
   GolfDataFactory theFact;
}