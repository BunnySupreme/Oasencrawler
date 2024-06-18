#include "Game.h"
#include <time.h>
#include <stdlib.h>

#include "Config.h"

#define TEST 0

Game::Game(int difficulty_level)
{
    if (difficulty_level < 0)
    {
        std::cout << "Error at Game Start: Difficulty level below 0";
    }
    //ctor
    difficulty_level_ = difficulty_level;
    gameworld_.createMap(player_.getXCoordinate(), player_.getYCoordinate());
    gameMessage(START_GAME_MESSAGE);
    player_.assignStatsRandomly();
}



//Getter
int Game::getDifficultyLevel() const
{
    return difficulty_level_;
}


void Game::renderGame()
{
    gameworld_.updatePlayerLocationOnMap(player_.getXCoordinate(), player_.getYCoordinate(), player_.getPrevXCoordinate(), player_.getPrevYCoordinate());
    player_.printStatus();
    gameworld_.printMap(enemy_.getEnemyXCoordinate(), enemy_.getEnemyYCoordinate());


}

char Game::getInput()
{
    controls_.askInput();
    return controls_.getInput();
}


void Game::movePlayer(char input)
{

    if (gameworld_.hitWall(input, player_.getXCoordinate(), player_.getYCoordinate()))
    {

        throw std::out_of_range("Hit a wall");

    }
    switch(input)
    {
        case NORTH:
            player_.moveNorth();
            break;
        case SOUTH:
            player_.moveSouth();
            break;
        case EAST:
            player_.moveEast();
            break;
        case WEST:
            player_.moveWest();
            break;
        default:
            errorMessage(ERROR_MESSAGE_WRONG_INPUT);
            renderGame();//Show map and status again

    }


}

void Game::checkEvent()
{
 //check if player went to a special field:
    if (enemy_.enemyReachedPlayer(player_.getXCoordinate(), player_.getYCoordinate()))
    {
        enemyCaptured();
        return;
    }
    char field_type_where_player = gameworld_.getFieldTypeWherePlayer(player_.getXCoordinate(), player_.getYCoordinate());
    if(field_type_where_player == gameworld_.getDangerFieldSymbol())
    {
        int what_happened = -1; //initialize with invalid value || this variable will save, what happened: 0 failed challenge, 1 succeeded, 2 succeeded but used item
        Challenge::CHALLENGE_TYPE challenge = challenges_.determineRandomChallenge();
        int item_type = (int)challenge;
        if (challenge == Challenge::CHALLENGE_TYPE::strength)
        {
            what_happened = challenges_.strengthChallenge(player_.getCurrentStrength(), player_.getCurrentItems(item_type));
        }
        else if(challenge == Challenge::CHALLENGE_TYPE::agility)
        {
            what_happened = challenges_.agilityChallenge(player_.getCurrentAgility(), player_.getCurrentItems(item_type));
        }
        else if(challenge == Challenge::CHALLENGE_TYPE::intelligence)
        {
            what_happened = challenges_.intelligenceChallenge(player_.getCurrentIntelligence(), player_.getCurrentItems(item_type));
        }
        if (what_happened == 2)
        {
            player_.loseItem(item_type);
        }
        if (what_happened == 0)
        {
            player_.loseHealthPoint();
        }

    }

    if (player_.getCurrentHealthPoints() == 0)
    {
        gameMessage(LOST_ALL_HEALTH_POINTS_MESSAGE);
        gameMessage(GAME_OVER_MESSAGE);
        game_over_ = true;
    }

    else if (field_type_where_player == gameworld_.getRelicFieldSymbol())
    {
        player_.gainRelicPoint();
        gameMessage(GOT_RELIC_MESSAGE);
        gameworld_.removeOneRelic();
        player_.gainItem(gameworld_.findItem());

    }
    else if (field_type_where_player == gameworld_.getFountainFieldSymbol())
    {
        if (player_.getCurrentHealthPoints() == 5)
        {
            std::cout << ALREADY_AT_MAX_HP_MESSAGE;
        }
        else
        {
            player_.gainHealthPoint();
            std::cout << GOT_HEALTH_POINT_MESSAGE;
        }
        player_.gainItem(gameworld_.findItem());
    }

    if (gameworld_.getNumberOfRelics() <= 0)
    {
        std::cout << GOT_ALL_RELICS_MESSAGE << LEVEL_WON_MESSAGE;
        gameworld_.createMap(player_.getXCoordinate(), player_.getYCoordinate());
        incrementDifficultyLevel();
        level_won_ = true;
    }
}

void Game::enemyTurn()
{
    gameworld_.updatePlayerLocationOnMap(player_.getXCoordinate(), player_.getYCoordinate(), player_.getPrevXCoordinate(), player_.getPrevYCoordinate());
    enemy_.moveEnemy(player_.getXCoordinate(), player_.getYCoordinate(), difficulty_level_, gameworld_.getMapSize());
    if (enemy_.enemyReachedPlayer(player_.getXCoordinate(), player_.getYCoordinate()))
    {
        enemyCaptured();
    }
}

void Game::startOfRoundHouseKeeping()
{
    level_won_ = false; //resets level won from prev level
}

void Game::gameMessage(const std::string& game_message)
{
    std::cout<<game_message;
}

void Game::errorMessage(const std::string& error_message)
{
    std::cout<<TEXT_SEPERATOR;
    std::cout<<error_message;
}

void Game::nextScreen()
{
    std::cout << TEXT_SEPERATOR;
}

void Game::incrementDifficultyLevel()
{
    difficulty_level_++;
}

bool Game::isGameOver() const
{
    return game_over_;
}
bool Game::isLevelWon() const
{
    return level_won_;
}

int Game::getPlayerXCoordinate() const
{
    return player_.getXCoordinate();
}

int Game::getPlayerYCoordinate() const
{
    return player_.getYCoordinate();
}


int Game::getMapSize() const
{
    return gameworld_.getMapSize();
}

int Game::getEnemyXCoordinate() const
{
    return enemy_.getEnemyXCoordinate();
}

int Game::getEnemyYCoordinate() const
{
    return enemy_.getEnemyYCoordinate();
}

int Game::getPlayerHealth() const
{
    return player_.getCurrentHealthPoints();
}

int Game::getPlayerItems(int item_type) const
{
    return player_.getCurrentItems(item_type);
}


void Game::enemyCaptured()
{
    gameworld_.printMap(enemy_.getEnemyXCoordinate(), enemy_.getEnemyYCoordinate());
    std::cout << ENEMY_CAPTURED_YOU_MESSAGE;
    std::cout << GAME_OVER_MESSAGE;
    game_over_ = true;
}

void Game::playerLosesHealth()
{
    player_--;
}
