#include "Challenge.h"


#include <stdlib.h>
#include <iostream>

#include "Config.h"

    //Challenge Messages
#define STRENGTH_TEST_MESSAGE "\nA boulder is in your way! You need to push it away."
#define STRENGTH_TEST_SUCCESS_MESSAGE "\nYou managed to push away the boulder easily!\n"
#define STRENGTH_TEST_FAILURE_MESSAGE "\nOh no! The boulder crushed your foot! You lose 1 health point.\n"
#define AGILITY_TEST_MESSAGE "\nThere is crevice you need to jump over."
#define AGILITY_TEST_SUCCESS_MESSAGE "\nYou skillfuly jumped over the crevice!\n"
#define AGILITY_TEST_FAILURE_MESSAGE "\nOh no! You fell into the crevice and hurt your ankle, losing 1 health point in the process.\n"
#define INTELLIGENCE_TEST_MESSAGE "\nYou need to solve a puzzle to get past this door."
#define INTELLIGENCE_TEST_SUCCESS_MESSAGE "\nThanks to your cleverness, you easily solve the puzzle.\n"
#define INTELLIGENCE_TEST_FAILURE_MESSAGE "\nOh no! All that thinking distracted you and you get a heat stroke! You lose 1 health point\n"

    //Use Item Messages
#define USE_ITEM_MESSAGE "\nHowever, you needed to use a potion to overcome this challenge\n";


//System Error Messages
#define ERROR_MESSAGE_CHALLENGE_FUNCTION_RETURN_VALUE "\nError with challenge function! Return value invalid.\n"
#define ERROR_MESSAGE_ABILITY_OUT_OF_BOUNDS "\nError in challenge function. Ability out of bounds.\n"
#define ERROR_MESSAGE_ITEMS_BELOW_0 "\nError in challenge function. Items below 0.\n"
#define ERROR_MESSAGE_ITEM_TYPE_OUT_OF_BOUNDS"\nError in challenge function. Item Type out of bounds.\n"

Challenge::Challenge()
{
    //ctor
}

Challenge::CHALLENGE_TYPE Challenge::determineRandomChallenge()
{
            return (CHALLENGE_TYPE)(rand() % types_of_challenges_);
}
int Challenge::strengthChallenge(int player_strength, int player_strength_items)
{

    testForErrors(player_strength, player_strength_items, STRENGTH_ITEM);

    int return_value;
    std::cout << STRENGTH_TEST_MESSAGE;
    return_value = beatChallenge(player_strength, player_strength_items, STRENGTH_ITEM);
    if (return_value == challenge_succeeded_)
    {
        std::cout << STRENGTH_TEST_SUCCESS_MESSAGE;
    }
    else if (return_value == challenge_failed_)
    {
        std::cout << STRENGTH_TEST_FAILURE_MESSAGE;
    }

    else if (return_value == challenge_succeeded_but_used_item_)
    {
        std::cout << USE_ITEM_MESSAGE;
    }
    else
    {
        std::cout<< ERROR_MESSAGE_CHALLENGE_FUNCTION_RETURN_VALUE;
    }

    return return_value;
}

int Challenge::agilityChallenge(int player_agility, int player_agility_items)
{
    testForErrors(player_agility, player_agility_items, AGILITY_ITEM);

    int return_value;
    std::cout << AGILITY_TEST_MESSAGE;
    return_value = beatChallenge(player_agility, player_agility_items, AGILITY_ITEM);
    if (return_value == challenge_succeeded_)
    {
        std::cout << AGILITY_TEST_SUCCESS_MESSAGE;
    }
    else if (return_value == challenge_failed_)
    {
        std::cout << AGILITY_TEST_FAILURE_MESSAGE;
    }

    else if (return_value == CHALLENGE_SUCCEEDED_BUT_USED_ITEM)
    {
        std::cout << USE_ITEM_MESSAGE;
    }
    else
    {
        std::cout << ERROR_MESSAGE_CHALLENGE_FUNCTION_RETURN_VALUE;
    }

    return return_value;
}

int Challenge::intelligenceChallenge(int player_intelligence, int player_intelligence_items)
{
    testForErrors(player_intelligence, player_intelligence_items, INTELLIGENCE_ITEM);

    int return_value;
    std::cout << INTELLIGENCE_TEST_MESSAGE;
    return_value = beatChallenge(player_intelligence, player_intelligence_items, INTELLIGENCE_ITEM);
    if (return_value)
    {
        std::cout << INTELLIGENCE_TEST_SUCCESS_MESSAGE;
    }
    else
    {
        std::cout << INTELLIGENCE_TEST_FAILURE_MESSAGE;
    }

    if (return_value >= CHALLENGE_SUCCEEDED_BUT_USED_ITEM)
    {
        std::cout << USE_ITEM_MESSAGE;
    }

    return return_value;
}

//return value: 0 means lost, 1 means won, 2 means won, but player used an item
int Challenge::beatChallenge(int attribute, int attribute_items, int item_type)
{
    testForErrors(attribute, attribute_items, item_type);

    int challenge_difficulty = rand() % max_challenge_difficulty_;
    if (attribute >= challenge_difficulty)
    {
        return CHALLENGE_SUCCEEDED;
    }
    else
    {
        if (attribute_items >= 1)
        {
            return CHALLENGE_SUCCEEDED_BUT_USED_ITEM;
        }
        return CHALLENGE_FAILED;
    }
}

void Challenge::testForErrors(int ability, int items, int item_type)
{
    if (ability < 1 || ability > MAX_ABILITY)
    {
        std::cout << ERROR_MESSAGE_ABILITY_OUT_OF_BOUNDS;
    }
    if (items < 0)
    {
        std::cout << ERROR_MESSAGE_ITEMS_BELOW_0;
    }
    if (item_type < 0 || item_type > TYPES_OF_ITEMS)
    {
        std::cout << ERROR_MESSAGE_ITEM_TYPE_OUT_OF_BOUNDS;
    }
}
