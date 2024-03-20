#include "Player.h"
#include <iostream>

#include "Config.h"



Player::Player()
{
   //ctor
}

/*
Player::Player(int starting_health_points, int starting_relic_points, int starting_xCoordinate, int starting_yCoordinate, char player_symbol, int strength, int agility, int intelligence, int strength_items, int agility_items, int intelligence_items)
{
    //ctor
    current_health_points_ = starting_health_points;
    current_relic_points_ = starting_relic_points;
    x_coordinate_ = starting_xCoordinate;
    y_coordinate_ = starting_yCoordinate;
    player_symbol_ = player_symbol;
    agility_ = agility;
    strength_ = strength;
    intelligence_ = intelligence;
    strength_items_ = strength_items;
    agility_items_ = agility_items;
    intelligence_items_ = intelligence_items;
}
*/

//Getter


int Player::getXCoordinate() const
{
    return x_coordinate_;
}
int Player::getYCoordinate() const
{
    return y_coordinate_;
}

int Player::getPrevXCoordinate() const
{
    return previous_x_coordinate_;
}

int Player::getPrevYCoordinate() const
{
    return previous_y_coordinate_;
}


int Player::getCurrentHealthPoints() const
{
    return current_health_points_;
}

int Player::getCurrentRelicPoints() const
{
    return current_relic_points_;
}

int Player::getCurrentStrength() const
{
    return strength_;
}
int Player::getCurrentAgility() const
{
    return agility_;
}
int Player::getCurrentIntelligence() const
{
    return intelligence_;
}

int Player::getCurrentItems(int item_type) const
{
    switch(item_type)
    {
        case STRENGTH_ITEM:
            return strength_items_;
            break;
        case AGILITY_ITEM:
            return agility_items_;
            break;
        case INTELLIGENCE_ITEM:
            return intelligence_items_;
            break;
    }
    return -1;
}


//movement
void Player::moveSouth()
{
    previous_x_coordinate_ = x_coordinate_;
    previous_y_coordinate_ = y_coordinate_;
    y_coordinate_++;
}

void Player::moveNorth()
{
    previous_x_coordinate_ = x_coordinate_;
    previous_y_coordinate_ = y_coordinate_;
    y_coordinate_--;
}

void Player::moveEast()
{
    previous_x_coordinate_ = x_coordinate_;
    previous_y_coordinate_ = y_coordinate_;
    x_coordinate_++;
}

void Player::moveWest()
{
    previous_x_coordinate_ = x_coordinate_;
    previous_y_coordinate_ = y_coordinate_;
    x_coordinate_--;
}

//Gain / lose
void Player::loseHealthPoint()
{
    current_health_points_--;
    if (current_health_points_ < 0)
    {
        current_health_points_ = 0;
    }
}

void Player::gainHealthPoint()
{
    current_health_points_++;
    if (current_health_points_ > MAX_HEALTH)
    {
        current_health_points_ = MAX_HEALTH;
    }
}

void Player::gainRelicPoint()
{
    current_relic_points_++;
}

void Player::gainItem(int item_type)
{
    testItemType(item_type);
    switch(item_type)
    {
        case STRENGTH_ITEM:
            strength_items_++;
            break;
        case AGILITY_ITEM:
            agility_items_++;
            break;
        case INTELLIGENCE_ITEM:
            intelligence_items_++;
            break;
    }
}

void Player::loseItem(int item_type)
{
    testItemType(item_type);
    switch(item_type)
    {
        case STRENGTH_ITEM:
            strength_items_--;
            break;
        case AGILITY_ITEM:
            agility_items_--;
            break;
        case INTELLIGENCE_ITEM:
            intelligence_items_--;
            break;
    }
}

void Player::printStatus()
{

    std::cout << std::endl;
    std::cout << "Current Health: " << current_health_points_ << "| ";
    std::cout << "Collected Relics: " << current_relic_points_ << std::endl;
    std::cout << "Strength: " << strength_<< "| ";
    std::cout << "Agility: " << agility_<< "| ";
    std::cout << "Intelligence: " << intelligence_<< std::endl;
    std::cout << "Potions: " << std::endl;
    std::cout << "Strength: " << strength_items_<< "| ";
    std::cout << "Agility: " << agility_items_<< "| ";
    std::cout << "Intelligence: " << intelligence_items_<< std::endl;

}

void Player::assignStatsRandomly()
{
    strength_ = rand() % MAX_ABILITY + 1;
    agility_ = rand() % MAX_ABILITY + 1;
    intelligence_ = rand() % MAX_ABILITY + 1;
}

void Player::testItemType(int item_type)
{
    if (item_type < 0  || item_type > TYPES_OF_ITEMS)
    {
        std::cout << "Error in Player Function! Item types out of bound.";
    }
}
