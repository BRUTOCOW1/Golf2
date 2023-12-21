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

string strInLow(string prompt)
{
    cout << "Please Enter " << prompt << ": ";
    std::string payload;
    getline(cin,payload,'\n');
    transform(payload.begin(), payload.end(), payload.begin(), ::tolower);

    return payload;
}

string strInLow(string prompt, std::vector<std::string>& vec)
{
    cout << "Please Enter " << prompt << ": " << endl;
    cout << "Options:" << endl;
    for (auto i : vec)
    {
        cout << i << "      "; 
    }

    std::string payload;
    getline(cin,payload,'\n');
    transform(payload.begin(), payload.end(), payload.begin(), ::tolower);

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
enum class HolePar { THREE, FOUR, FIVE };
enum class HoleTopo {FLAT, UP, DOWN};
enum class HoleHazard {WATER, BUNKER, MANMADE};

/* Shots */
enum class ShotDirection {HOOK, DRAW, SHOTSTRAIGHT, FADE, SLICE};
enum class ShotError {PUSH, PULL, TOP, DUFF, SHANK, NONE};
enum class ShotType {TEE, FAIRWAY, APPROACH, PITCH, BUNKER, CHIP, PUTT};


/* Lie */
enum class LiePlacement {RIGHT, LEFT, FRONT, BACK, CENTER, RIGHTCENTER, LEFTCENTER };
enum class LieLocation {TEEBOX, ROUGH, FAIRWAY, FRINGE, GREEN, BUNKER, HAZARD};


/* Scoring */
enum class Score {ALBATROSS, EAGLE, BIRDIE, PAR, BOGEY, DBOGEY, TBOGEY, QBOGEY};


/** Vectors */

/* Clubs */
std::vector<std::string> clubMakeNames{"two", "three", "four", "five", "six", "seven", "eight", "nine", "pitching", "gap", "sand"};
std::vector<std::string> clubModelNames{"putter", "wedge", "iron", "wood"};

/* Holes */
std::vector<std::string> holeTTGNames{"straight", "right", "left"};
std::vector<std::string> holeShapeNames{"straight", "dogleg"};
std::vector<std::string> holeParNames{"three", "four", "five"};
std::vector<std::string> holeTopoNames{"flat", "up", "down"};
std::vector<std::string> holeHazardNames{"water", "bunker", "manmade"};

/* Shots */
std::vector<std::string> shotDirectionNames{"hook", "draw", "straight", "fade", "slice"};
std::vector<std::string> shotErrorNames{"push", "pull", "top", "duff", "shank", "none"};
std::vector<std::string> shotTypeNames{"tee", "fairway", "approach", "pitch", "bunker", "chip", "putt"};


/* Scoring*/
std::vector<std::string> scoreNames {"Albatross", "Eagle", "Birdie", "Par", "Bogey", "Double Bogey", "Triple Bogey", "Quad Bogey"};

/* Lies */
std::vector<std::string> liePlacementNames {"right", "left", "front", "back", "center", "center right", "center left"};
std::vector<std::string> lieLocationNames {"tee box", "rough", "fairway", "fringe", "green", "bunker", "hazard"};


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

/* Lies */
std::map<std::string, LiePlacement> liePlacements;
std::map<std::string, LieLocation> lieLocations;

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

    popOpts<LiePlacement>(liePlacementNames, liePlacements);
    popOpts<LieLocation>(lieLocationNames, lieLocations);


}



#endif // MYENUM_HPP