#include "Enemy.h"

#include <stdlib.h>
#include <iostream>
#include "Config.h"


Enemy::Enemy()
{

}

Enemy::Enemy(int enemy_x_coordinate, int enemy_y_coordinate)
{
    testCoordinates(enemy_x_coordinate, enemy_y_coordinate);

    enemy_x_coordinate_ = enemy_y_coordinate;
    enemy_y_coordinate_ = enemy_y_coordinate;
    //ctor
}

//Getter
int Enemy::getEnemyXCoordinate() const
{
    return enemy_x_coordinate_;
}

int Enemy::getEnemyYCoordinate() const
{
    return enemy_y_coordinate_;
}


void Enemy::moveEnemy(int player_x_coordinate, int player_y_coordinate, int difficulty_level, int map_size)
{
    testCoordinates(player_x_coordinate, player_y_coordinate);
    if (difficulty_level < 0)
    {
        std::cout << "Error in Enemy function: Difficulty below 0";
    }
    if (map_size < 0 ||map_size > MAP_SIZE)
    {
        std::cout << "Error in Enemy function: Map Size out of invalid";
    }

    int probability_of_random_movement = 10 - difficulty_level;     //the higher difficulty level, the higher the probability. Starts at 9, then goes all the way to 0 at difficulty 10
    int random_number = 0;

    //Enemy decides to move randomly. Happens a lot on lower difficulty level
    random_number = rand() % 10 + 1;
    if (random_number <= probability_of_random_movement)
    {
        moveEnemyRandomly(map_size);
        return;
    }

    //Chasing player
    if (player_x_coordinate == enemy_x_coordinate_)
    {
        chasePlayerYCoordinate(player_y_coordinate);
    }

    else if (player_y_coordinate == enemy_y_coordinate_)
    {
        chasePlayerXCoordinate(player_x_coordinate);
    }
    else
    {
        int coin_flip = rand() % 2;
        switch (coin_flip)
        {
            case 0:
                chasePlayerXCoordinate(player_x_coordinate);
                break;
            case 1:
                chasePlayerYCoordinate(player_y_coordinate);
                break;
        }
    }

}

bool Enemy::enemyReachedPlayer(int player_x_coordinate, int player_y_coordinate)
{

    if (player_x_coordinate == enemy_x_coordinate_ && player_y_coordinate == enemy_y_coordinate_)
    {
        return true;
    }

    return false;
}

//private functions

void Enemy::moveEnemyRandomly(int map_size)
{
    int map_limit = map_size-1;

    while(1)
    {
        int random_direction = rand() % 4;
        bool need_to_try_again = false;
        switch (random_direction)
        {
        case 0:
            enemy_x_coordinate_++;
            break;
        case 1:
            enemy_x_coordinate_--;
            break;
        case 2:
            enemy_y_coordinate_++;
            break;
        case 3:
            enemy_y_coordinate_--;
            break;
        }
        if (enemy_x_coordinate_ > map_limit)
        {
            enemy_x_coordinate_--;
            need_to_try_again = true;
        }
        else if (enemy_x_coordinate_ < 0)
        {
            enemy_x_coordinate_++;
            need_to_try_again = true;
        }
        else if (enemy_y_coordinate_ > map_limit)
        {
            enemy_y_coordinate_--;
            need_to_try_again = true;
        }
        else if (enemy_y_coordinate_ < 0)
        {
            enemy_y_coordinate_++;
            need_to_try_again = true;
        }
        if (need_to_try_again == false)
        {
            break;
        }

    }
}

void Enemy::chasePlayerYCoordinate(int player_y_coordinate)
{

    if (player_y_coordinate > enemy_y_coordinate_)
    {
        enemy_y_coordinate_++;
    }
    else
    {
        enemy_y_coordinate_--;
    }
}

void Enemy::chasePlayerXCoordinate(int player_x_coordinate)
{

    if (player_x_coordinate > enemy_x_coordinate_)
    {
        enemy_x_coordinate_++;
    }
    else
    {
        enemy_x_coordinate_--;
    }
}





void Enemy::testCoordinates(int x_coordinate, int y_coordinate)
{
    if(x_coordinate < 0 || x_coordinate > MAX_X_COORDINATE ||y_coordinate < 0 || y_coordinate > MAX_Y_COORDINATE)
    {
        std::cout << "Error with coordinates! check Enemy function";
    }
}





