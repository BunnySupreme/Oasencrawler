#ifndef PLAYER_H
#define PLAYER_H
#include <stdlib.h>

#include "Config.h"



class Player
{
    public:
        Player();
        //Getter
        int getXCoordinate() const;
        int getYCoordinate() const;
        int getPrevXCoordinate() const;
        int getPrevYCoordinate() const;
        int getCurrentHealthPoints() const;
        int getCurrentRelicPoints() const;
        int getCurrentStrength() const;
        int getCurrentAgility() const;
        int getCurrentIntelligence() const;
        int getCurrentItems(int item_type) const;
        //other functions
        void moveNorth();
        void moveSouth();
        void moveEast();
        void moveWest();
        void loseHealthPoint();
        void gainHealthPoint();
        void gainRelicPoint();
        void gainItem(int item_type);
        void loseItem(int item_type);
        void printStatus();
        void assignStatsRandomly();
        //operator overload
        void operator++();
        void operator++(int);
        void operator--();  //prefix decrement
        void operator--(int); //for postfix, add seperate function with int parameter




    protected:

    private:
        int x_coordinate_ = STARTING_X_COORDINATE;
        int y_coordinate_ = STARTING_Y_COORDINATE;
        int previous_x_coordinate_ = STARTING_X_COORDINATE; //previous location also set to starting location
        int previous_y_coordinate_ = STARTING_Y_COORDINATE;
        int current_health_points_ = STARTING_HEALTH;
        int current_relic_points_ = STARTING_RELIC_POINTS;
        int strength_ = 0;
        int agility_ = 0;
        int intelligence_ = 0;
        int strength_items_ = STARTING_ITEMS;
        int agility_items_ = STARTING_ITEMS;
        int intelligence_items_ = STARTING_ITEMS;
        char player_symbol_ = PLAYER_SYMBOL;
        //internal functions
        void testItemType(int item_type);

};

#endif // PLAYER_H
