#ifndef ENEMIES_H
#define ENEMIES_H

#define MAX_ENEMY_AMOUNT 25

class Enemies
{
    public:
        Enemies(int first_enemy_x_coordinate, int first_enemy_y_coordinate);
        void initNewEnemy(int player_x_coordinate, int player_y_coordinate, int map_size);
        //getter
        const int* getEnemiesXCoordinatePointer() const;
        const int* getEnemiesYCoordinatePointer() const;
        int getEnemyAmount() const;

        virtual ~Enemies();

    protected:

    private:
    int enemies_x_coordinate_[MAX_ENEMY_AMOUNT];
    int enemies_y_coordinate_[MAX_ENEMY_AMOUNT];
    int enemy_amount_ = 1;
};

#endif // ENEMIES_H
