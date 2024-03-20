#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

//Player
#define PLAYER_SYMBOL '@'
#define STARTING_HEALTH 5
#define MAX_HEALTH 5
#define STARTING_RELIC_POINTS 0
#define STARTING_X_COORDINATE 0
#define STARTING_Y_COORDINATE 0
#define PLAYER_STARTING_PREVIOUS_COORDINATE -1
#define STARTING_ITEMS 0
#define MAX_ABILITY 3

//Map
#define MAP_SIZE 5
#define MAX_X_COORDINATE MAP_SIZE-1
#define MAX_Y_COORDINATE MAP_SIZE-1

//Field types
#define EMPTY_FIELD '.'
#define DANGER_FIELD '^'
#define FOUNTAIN_FIELD '+'
#define RELIC_FIELD '*'
#define ENEMY_SYMBOL 'X'
#define PLAYER_SYMBOL '@'

//Field type probabilites
#define EMPTY_FIELD_PROBABILITY_LOWER_BOUND 0
#define EMPTY_FIELD_PROBABILITY_UPPER_BOUND 3
#define DANGER_PROBABILITY_LOWER_BOUND 4
#define DANGER_PROBABILITY_UPPER_BOUND 7
#define FOUNTAIN_PROBABILITY 8
#define RELIC_PROBABILITY 9

//Movement
#define NORTH 'n'
#define SOUTH 's'
#define EAST 'e'
#define WEST 'w'

//Enemy
#define FIRST_ENEMY_STARTING_X_COORDINATE 4
#define FIRST_ENEMY_STARTING_Y_COORDINATE 4

//Challenges
#define TYPES_OF_CHALLENGES 3
#define STRENGTH_CHALLENGE 0
#define AGILITY_CHALLENGE 1
#define INTELLIGENCE_CHALLENGE 2
#define MAX_CHALLENGE_DIFFICULTY 5
#define CHALLENGE_FAILED 0
#define CHALLENGE_SUCCEEDED 1
#define CHALLENGE_SUCCEEDED_BUT_USED_ITEM 2

//Items
#define TYPES_OF_ITEMS 3
#define STRENGTH_ITEM 0
#define AGILITY_ITEM 1
#define INTELLIGENCE_ITEM 2
#define STARTING_ITEMS 0
#define USED_STRENGTH_POTION 2
#define USED_AGILITY_POTION 3
#define USED_INTELLIGENCE_POTION 4

//Messages
    //Game Status Messages
#define START_GAME_MESSAGE "\nQuickly! Get all the relics! If the enemies capture you, it's all over!\n"
#define LEVEL_WON_MESSAGE "\n\nCongratulations! You won this level!\nThere are more relics to find, but watch out! The enemy is more aware of you now!\n"
#define GAME_OVER_MESSAGE "\nGAME OVER!\n"
#define TEXT_SEPERATOR "\n--------------------------------------------------\n"


    //Map Messages
#define LEGEND_MESSAGE "LEGEND:\n"<<PLAYER_SYMBOL<<" is you, the Player\n"<<EMPTY_FIELD<<" is an empty field\n"<<DANGER_FIELD<<" is a danger field\n"<<FOUNTAIN_FIELD<<" is a fountain\n"<<RELIC_FIELD<<" is a relic\n"<<ENEMY_SYMBOL<<" is an enemy\n"

    //Found Things Messages
#define GOT_RELIC_MESSAGE "\nYou found a relic!\n"
#define GOT_ALL_RELICS_MESSAGE "\nYou managed to get all the relics! Good job!"
#define FIND_STRENGTH_ITEM_MESSAGE "\nYou also found a strength potion!\n"
#define FIND_AGILITY_ITEM_MESSAGE "\nYou also found an agility potion!\n"
#define FIND_INTELLIGENCE_ITEM_MESSAGE "\nYou also found an intelligence potion!\n"


#define LOST_ALL_HEALTH_POINTS_MESSAGE "\nYou lost all health points!\n"
#define ALREADY_AT_MAX_HP_MESSAGE "\nYou were already at max health! After resting at the fountain, you feel as well as before.\n"
#define GOT_HEALTH_POINT_MESSAGE "\nYou rested at the fountain and recovered one health point!\n"
#define ENEMY_CAPTURED_YOU_MESSAGE "\nOh no! The enemy has captured you!"

    //Error Messages
#define ERROR_MESSAGE_HIT_WALL "\nYou have reached the end of the map! Go another way. Put in another input please.\n"
#define ERROR_MESSAGE_WRONG_INPUT "\nThat input is not valid! Please try again.\n"







#endif // CONFIG_H_INCLUDED
