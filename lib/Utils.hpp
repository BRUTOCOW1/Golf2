#pragma once


#ifndef MYENUM_HPP
#define MYENUM_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;





std::string twoBreaks = "\n \n";


constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

string strIn(string prompt)
{
    cout << "Please Enter " << prompt << ": ";
    std::string payload;
    getline(cin,payload,'\n');
    return payload;
}

int intIn(string prompt)
{
    cout << "Please Enter " << prompt << ": ";
    std::string payload;
    getline(cin,payload,'\n');
    return stoi(payload);
}

std::vector<std::string> simple_tokenizer(string s)
{
    std::vector<std::string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

/* Enums */

/* Clubs */
enum class ClubMake {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, PITCHING, GAP, SAND};
enum class ClubModel {PUTTER, WEDGE, IRON, WOOD};

/* Holes */
enum class HoleTTG { TTGSTRAIGHT, RIGHT, LEFT};
enum class HoleShape { HOLESTRAIGHT, DOGLEG };
enum class HoleTopo {FLAT, UP, DOWN};
enum class HoleHazard {WATER, BUNKER, MANMADE};

/* Shots */
enum class ShotDirection {HOOK, DRAW, SHOTSTRAIGHT, FADE, SLICE};
enum class ShotError {PUSH, PULL, TOP, DUFF, SHANK, NONE};
enum class ShotType {TEE, FAIRWAY, APPROACH, PITCH, BUNKER, CHIP, PUTT};


/** Vectors */

/* Clubs */
std::vector<std::string> clubMakeNames{"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Pitching", "Gap", "Sand"};
std::vector<std::string> clubModelNames{"Putter", "Wedge", "Iron", "Wood"};

/* Holes */
std::vector<std::string> holeTTGNames{"Straight", "Right", "Left"};
std::vector<std::string> holeShapeNames{"Straight", "Dogleg"};
std::vector<std::string> holeTopoNames{"Flat", "Up", "Down"};
std::vector<std::string> holeHazardNames{"Water", "Bunker", "MANMADE"};

/* Shots */
std::vector<std::string> shotDirectionNames{"Hook", "Draw", "Straight", "Fade", "Slice"};
std::vector<std::string> shotErrorNames{"Push", "Pull", "Top", "Duff", "Shank", "None"};
std::vector<std::string> shotTypeNames{"Tee", "Fairway", "Approach", "Pitch", "Bunker", "Chip", "Putt"};


/** Maps */

/* Clubs */
std::map<std::string, ClubMake> clubMakes;
std::map<std::string, ClubModel> clubModels;

/* Holes */
std::map<std::string, HoleTTG> holeTTGs;
std::map<std::string, HoleShape> holeShapes;
std::map<std::string, HoleTopo> holeTopos;
std::map<std::string, HoleHazard> holeHazards;

/* Shots */
std::map<std::string, ShotDirection> shotDirections;
std::map<std::string, ShotError> shotErrors;
std::map<std::string, ShotType> shotTypes;



template<typename T>
void popOpts(const std::vector<string>& sv, std::map<string, T>& mp){

    for (std::size_t i = 0; i < sv.size(); i++){
        mp[sv[i]] = static_cast<T>(i);
    }

}

void popAllOpts(){
    popOpts<ClubMake>(clubMakeNames, clubMakes);
    popOpts<ClubModel>(clubModelNames, clubModels);

    popOpts<HoleTTG>(holeTTGNames, holeTTGs);
    popOpts<HoleShape>(holeShapeNames, holeShapes);
    popOpts<HoleTopo>(holeTopoNames, holeTopos);
    popOpts<HoleHazard>(holeHazardNames, holeHazards);

    popOpts<ShotDirection>(shotDirectionNames, shotDirections);
    popOpts<ShotError>(shotErrorNames, shotErrors);
    popOpts<ShotType>(shotTypeNames, shotTypes);


}

#endif // MYENUM_HPP