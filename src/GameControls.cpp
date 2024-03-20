#include "GameControls.h"
#include <iostream>

#include "Config.h"

#define INPUT_MESSAGE "\nINPUT OPTIONS:\n(n) NORTH, (s) SOUTH, (e) EAST, (w) WEST \n\nPlease input, where you want to go next\n"
#define ERROR_MESSAGE_TOO_LONG "\nYou may only input one character! Try again.\n"



GameControls::GameControls()
{
    //ctor
}

void GameControls::askInput()
{
    std::string input; //string, so we can test if more than 1 char got input
    bool input_correct = false;
    while(input_correct == false)
    {
        std::cout << INPUT_MESSAGE;
        std::getline(std::cin, input);
        if (input.size() > 1)
        {
            std::cout << TEXT_SEPERATOR;
            std::cout << ERROR_MESSAGE_TOO_LONG;
        }
        else
        {
            input_correct = true;
        }
    }
    input_ = input[0];
}

char GameControls::getInput() const
{
    return input_;
}

