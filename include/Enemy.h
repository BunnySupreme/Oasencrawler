#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        Enemy(int enemy_x_coordinate, int enemy_y_coordinate);
        //getter
        int getEnemyXCoordinate() const;
        int getEnemyYCoordinate() const;
        //other functions
        void moveEnemy(int player_x_coordinate, int player_y_coordinate, int difficulty_level, int map_size);
        bool enemyReachedPlayer(int player_x_coordinate, int player_y_coordinate);

    private:
    int enemy_x_coordinate_ = 4;
    int enemy_y_coordinate_ = 4;
    //private Functions
    void moveEnemyRandomly(int map_size);
    void chasePlayerXCoordinate(int player_x_coordinate);
    void chasePlayerYCoordinate(int player_y_coordinate);
    void testCoordinates(int x_coordinate, int y_coordinate);

};

#endif // ENEMY_H
