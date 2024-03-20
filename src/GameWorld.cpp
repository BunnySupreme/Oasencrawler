#include "GameWorld.h"

#include <stdlib.h>
#include <iostream>




GameWorld::GameWorld()
{
    //couldn't draw Game World already because dependent on Player Coordinates, so done in Game constructor
}

//Getters
int GameWorld::getNumberOfRelics() const
{
    return number_of_relics_;
}

int GameWorld::getMapSize() const
{
    return map_size_;
}

char GameWorld::getDangerFieldSymbol() const
{
    return danger_field_;
}

char GameWorld::getRelicFieldSymbol() const
{
    return relic_field_;
}
char GameWorld::getFountainFieldSymbol() const
{
    return fountain_field_;
}

//other functions
void GameWorld::createMap(int player_x_coordinate, int player_y_coordinate)
{
    testCoordinates(player_x_coordinate, player_y_coordinate);

    number_of_relics_ = 0;
    bool atLeastOneRelic = false;

    for (int i = 0; i < MAP_SIZE; i++)  //i is row, y coordinate
    {
        for (int j = 0; j < MAP_SIZE; j++)  //j is colum, x coordinate
        {
            if (i == player_y_coordinate && j == player_x_coordinate)
            {
                map_[j][i] = EMPTY_FIELD; //initialize Player starting location as empty
                continue;
            }
            map_[j][i] = initRandomField();
            if (map_[j][i] == RELIC_FIELD)
            {
                atLeastOneRelic = true;
                number_of_relics_++;
            }
        }

    }
    if (atLeastOneRelic == false)
    {
        int randomX = 0;
        int randomY = 0;
        while(1)
        {
            randomX = rand()%5;
            randomY = rand()%5;
            if (randomX == 0 && randomY == 0)   //should not be starting location
            {
                continue;
            }
            else
            {
                break;
            }
        }
        map_[randomX][randomY] = RELIC_FIELD;
        number_of_relics_++;
    }
}

bool GameWorld::hitWall(char input, int player_x_coordinate, int player_y_coordinate)
{
    testCoordinates(player_x_coordinate, player_y_coordinate);
    //input already tested in Game::movePlayer function
    switch(input){
    case NORTH:
        if (player_y_coordinate <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case SOUTH:
        if (player_y_coordinate >= max_y_coordinate_)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case WEST:
        if (player_x_coordinate <= 0)
        {
            return true;
            return true;
        }
        else
        {
            return false;
        }
        break;
    case EAST:
        if (player_x_coordinate >= max_x_coordinate_)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    default:
        std::cout << "\nError in hitWall Function! Invalid input! Game continues.\n";
        return false;

    }
}



void GameWorld::updatePlayerLocationOnMap(int player_x_coordinate, int player_y_coordinate, int player_previous_x_coordinate, int player_previous_y_coordinate)
{
    testCoordinates(player_x_coordinate, player_y_coordinate);
    testCoordinates(player_previous_x_coordinate, player_previous_y_coordinate);
    //previous location is set to EMPTY FIELD, so that in the beginning of the game, current player location overrides prev player location
    map_[player_previous_x_coordinate][player_previous_y_coordinate] = EMPTY_FIELD;
    map_[player_x_coordinate][player_y_coordinate] = PLAYER_SYMBOL;

}

void GameWorld::printMap(int enemy_x_coordinate, int enemy_y_coordinate)
{
    std::cout << std::endl;
    std::cout << "MAP:\n";
    std::cout << "-------" << std::endl;
    for (int i = 0; i < MAP_SIZE; i++)  //i is column, y coordinate
    {
        std::cout<<"|";
        for (int j = 0; j < MAP_SIZE; j++)  //j is row, x coordinate
        {

            if (enemy_x_coordinate == j && enemy_y_coordinate == i)
            {
                std::cout << ENEMY_SYMBOL;
            }
            else
            {
                std::cout << map_[j][i];
            }
        }
        std::cout << "|";

        std::cout << std::endl;
    }
    std::cout << "-------" << std::endl;
    std::cout << LEGEND_MESSAGE;
}

char GameWorld::getFieldTypeWherePlayer(int player_x_coordinate, int player_y_coordinate)
{
    return map_[player_x_coordinate][player_y_coordinate];
}

void GameWorld::removeOneRelic()
{
    number_of_relics_--;
    if (number_of_relics_ < 0)
    {
        std::cout << "\nError! Number of Relics is smaller than 0! Number of Relics will be reset to 0\n";
        number_of_relics_ = 0;
    }
}

int GameWorld::findItem()
{
    int item = rand() % TYPES_OF_ITEMS;
    switch(item)
    {
        case STRENGTH_ITEM:
            std::cout << FIND_STRENGTH_ITEM_MESSAGE;
            break;
        case AGILITY_ITEM:
            std::cout << FIND_AGILITY_ITEM_MESSAGE;
            break;
        case INTELLIGENCE_ITEM:
            std::cout << FIND_INTELLIGENCE_ITEM_MESSAGE;
            break;
    }
    return item;
}


//private
char GameWorld::initRandomField()
{
    int random_number = rand()%10;
    if (random_number >= EMPTY_FIELD_PROBABILITY_LOWER_BOUND && random_number <= EMPTY_FIELD_PROBABILITY_UPPER_BOUND)
    {
        return empty_field_;
    }
    if (random_number >= DANGER_PROBABILITY_LOWER_BOUND && random_number <= DANGER_PROBABILITY_UPPER_BOUND)
    {
        return danger_field_;
    }
    if (random_number == FOUNTAIN_PROBABILITY)
    {
        return fountain_field_;
    }
    if (random_number == RELIC_PROBABILITY)
    {
        return relic_field_;
    }
    return '?'; //this is because otherwise warning from compiler: reaches end of function without return value
}

void GameWorld::testCoordinates(int x_coordinate, int y_coordinate)
{
    if(x_coordinate < 0 || x_coordinate > MAX_X_COORDINATE || y_coordinate < 0 || y_coordinate > MAX_Y_COORDINATE)
    {
        std::cout << "Error with coordinates! check GameWorld function";
    }
}
