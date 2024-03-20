#include "PLAYER.h"
#include "GameWorld.h"
#include "Challenge.h"
#include "GameControls.h"
#include "Enemy.h"
#include "Game.h"

#include <time.h>
#include <stdlib.h>

#define STARTING_DIFFICULTY_LEVEL 5

//main

int main()
{
    srand (time(NULL));    //set seed for random numbers
    Game game(STARTING_DIFFICULTY_LEVEL);
    while (1)
    {
        game.startOfRoundHouseKeeping();
        game.renderGame();
        game.movePlayer();
        game.nextScreen();  //just makes a seperator between screens
        game.checkEvent();
        if (game.isGameOver())
        {
            break;
        }
        if (game.isLevelWon())
        {
            continue;
        }
        game.enemyTurn();
        if (game.isGameOver())
        {
            break;
        }

    }
    return 0;
}














