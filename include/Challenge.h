#ifndef CHALLENGE_H
#define CHALLENGE_H

#include "Config.h"

class Challenge
{

    public:
        enum class CHALLENGE_TYPE{
            strength,
            agility,
            intelligence
        };

        Challenge();
        CHALLENGE_TYPE determineRandomChallenge();
        int strengthChallenge(int player_strength, int player_strength_items);
        int agilityChallenge(int player_strength, int player_strength_items);
        int intelligenceChallenge(int player_strength, int player_strength_items);

    private:
        int types_of_challenges_ = TYPES_OF_CHALLENGES;
        int max_challenge_difficulty_ = MAX_CHALLENGE_DIFFICULTY;
        int challenge_succeeded_ = CHALLENGE_SUCCEEDED;
        int challenge_failed_ = CHALLENGE_FAILED;
        int challenge_succeeded_but_used_item_ = CHALLENGE_SUCCEEDED_BUT_USED_ITEM;
        //internal functions
        int beatChallenge(int attribute, int attribute_items, int item_type);
        void testForErrors(int ability, int items, int item_type);
};

#endif // CHALLENGE_H
