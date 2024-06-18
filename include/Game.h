#ifndef GAME_H
#define GAME_H

#include "PLAYER.h"
#include "GameWorld.h"
#include "Challenge.h"
#include "GameControls.h"
#include "Enemy.h"

#include <iostream>




class Game
{
    public:
        explicit Game(int difficulty_level);
        //Getters
        int getDifficultyLevel() const;
        //other functions
        void renderGame();
        void movePlayer(char input);
        void checkEvent();
        void enemyTurn();
        void startOfRoundHouseKeeping();
        void nextScreen();
        bool isGameOver() const;
        bool isLevelWon() const;
        //new functions for testing
        int getPlayerXCoordinate() const;
        int getPlayerYCoordinate() const;
        int getEnemyXCoordinate() const;
        int getEnemyYCoordinate() const;
        int getMapSize() const;
        int getPlayerHealth() const;
        int getPlayerItems(int item_type) const;
        char getInput();
        void playerLosesHealth();


    private:
        Player player_;
        Enemy enemy_;
        GameWorld gameworld_;
        GameControls controls_;
        Challenge challenges_;
        int difficulty_level_;   //determines number of enemies and how aware they are of the player
        bool game_over_ = false;
        bool level_won_ = false;
        // private functions
        void enemyCaptured();
        void gameMessage(const std::string& game_message);
        void errorMessage(const std::string& error_message);
        void incrementDifficultyLevel();
};

#endif // GAME_H
