#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Config.h"


class GameWorld
{
    public:

        //Tried enum, but lots of if/else when printing
        /*
        enum class FIELD_TYPE
        {
            empty = 1,
            danger,
            relic,
            fountain,
            player
        };
        */
        GameWorld();
        //Getters
        int getNumberOfRelics() const;
        int getMapSize() const;
        char getDangerFieldSymbol() const;
        char getRelicFieldSymbol() const;
        char getFountainFieldSymbol() const;
        //other functions
        void createMap(int player_x_coordinate, int player_y_coordinate);
        bool hitWall(char input, int player_x_coordinate, int player_y_coordinate);
        void updatePlayerLocationOnMap(int player_x_coordinate, int player_y_coordinate, int player_previous_x_coordinate, int player_previous_y_coordinate);
        void printMap(int enemy_x_coordinate, int enemy_y_coordinate);
        char getFieldTypeWherePlayer(int player_x_coordinate, int player_y_coordinate);
        void removeOneRelic();
        int findItem();


    private:
        //Variables
        int number_of_relics_ = 0;
        int map_size_ = MAP_SIZE;
        char danger_field_ = DANGER_FIELD;
        char relic_field_ = RELIC_FIELD;
        char fountain_field_ = FOUNTAIN_FIELD;
        char empty_field_ = EMPTY_FIELD;
        char map_[MAP_SIZE][MAP_SIZE];
        int max_x_coordinate_ = MAX_X_COORDINATE;
        int max_y_coordinate_ = MAX_Y_COORDINATE;

        //internal Functions
        char initRandomField();
        void testCoordinates(int x_coordinate, int y_coordinate);

};

#endif // GAMEWORLD_H
