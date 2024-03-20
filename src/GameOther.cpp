#include "GameOther.h"
#include <time.h>
#include <stdlib.h>

#define TEXT_SEPERATOR "\n-----------------------------------------------------\n"

GameOther::GameOther(int difficulty_level)
{
    //ctor
    difficulty_level_ = difficulty_level;
}

void GameOther::setSeed()
{
    srand ( time(NULL));    //set seed for random numbers
}

void GameOther::gameMessage(std::string game_message)
{
    std::cout<<game_message;
}

void GameOther::errorMessage(std::string error_message)
{
    std::cout<<TEXT_SEPERATOR;
    std::cout<<error_message;
}

void GameOther::nextScreen()
{
    std::cout << TEXT_SEPERATOR;
}

void GameOther::incrementDifficultyLevel()
{
    difficulty_level_++;
}


//Getter
int GameOther::getDifficultyLevel() const
{
    return difficulty_level_;
}

GameOther::~GameOther()
{
    //dtor
}
