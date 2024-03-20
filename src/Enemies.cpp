#include "Enemy.h"
#include <stdlib.h>

Enemies::Enemies(int first_enemy_x_coordinate, int first_enemy_y_coordinate)
{
    enemies_x_coordinate_[0] = first_enemy_x_coordinate;
    enemies_y_coordinate_[0] = first_enemy_y_coordinate;
    //ctor
}
void Enemies::initNewEnemy(int player_x_coordinate, int player_y_coordinate, int map_size)
{
    int i = enemy_amount_;
    bool try_again = true;

    while(try_again == true)
    {
        try_again = false;
        enemies_x_coordinate_[i] = rand() % map_size;
        enemies_y_coordinate_[i] = rand() % map_size;
        if (enemies_x_coordinate_[i] == player_x_coordinate && enemies_y_coordinate_[i] == player_y_coordinate)
        {
            try_again = true;
        }

    }
    enemy_amount_++;


}

//Getter
const int* Enemies::getEnemiesXCoordinatePointer() const
{
    return enemies_x_coordinate_;
}

const int* Enemies::getEnemiesYCoordinatePointer() const
{
    return enemies_y_coordinate_;
}

int Enemies::getEnemyAmount() const
{
    return enemy_amount_;
}





Enemies::~Enemies()
{
    //dtor
}
