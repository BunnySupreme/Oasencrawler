#include "PLAYER.h"
#include "GameWorld.h"
#include "Challenge.h"
#include "GameControls.h"
#include "Enemy.h"
#include "Game.h"

#include "Config.h"

#include <time.h>
#include <stdlib.h>

#define STARTING_DIFFICULTY_LEVEL 5
#define MAX_DIFFICULTY_LEVEL 10

//main
#include <vector>
#include <utility>

#define TEST 1

#if TEST


    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
    #include "vendor/doctest/doctest.h"

    TEST_CASE("player can move") {
        srand(0);
        Game game(STARTING_DIFFICULTY_LEVEL);

        REQUIRE(game.getPlayerXCoordinate() == 0);
        REQUIRE(game.getPlayerYCoordinate() == 0);

        SUBCASE("player moves east, then west") {
            game.movePlayer(EAST);
            CHECK(game.getPlayerXCoordinate() == 1);
            CHECK(game.getPlayerYCoordinate() == 0);
            game.movePlayer(WEST);
            CHECK(game.getPlayerXCoordinate() == 0);
            CHECK(game.getPlayerYCoordinate() == 0);
        }

        SUBCASE("player moves south, then north") {
            game.movePlayer(SOUTH);
            CHECK(game.getPlayerXCoordinate() == 0);
            CHECK(game.getPlayerYCoordinate() == 1);
            game.movePlayer(NORTH);
            CHECK(game.getPlayerXCoordinate() == 0);
            CHECK(game.getPlayerYCoordinate() == 0);
        }





    }
    TEST_CASE("player cannot go out of bound") {
        srand (0);
        Game game(STARTING_DIFFICULTY_LEVEL);

        REQUIRE(game.getPlayerXCoordinate() == 0);
        REQUIRE(game.getPlayerYCoordinate() == 0);

         SUBCASE("Edge Case X: 0, Y: 0")
        {
            REQUIRE_THROWS_AS(game.movePlayer(NORTH), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == 0);
            CHECK(game.getPlayerYCoordinate() == 0);

            REQUIRE_THROWS_AS(game.movePlayer(WEST), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == 0);
            CHECK(game.getPlayerYCoordinate() == 0);
        }

        SUBCASE("Edge Case X: max, Y: max")
        {
            int maxCoordinate = game.getMapSize() - 1;

            for (int i = 0; i < maxCoordinate; i++)
            {
                game.movePlayer(EAST);
                game.movePlayer(SOUTH);
            }
            game.movePlayer(EAST); // Move to the max edge
            game.movePlayer(SOUTH); // Move to the max edge
            REQUIRE(game.getPlayerXCoordinate() == maxCoordinate);
            REQUIRE(game.getPlayerYCoordinate() == maxCoordinate);

            REQUIRE_THROWS_AS(game.movePlayer(EAST), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == maxCoordinate);
            CHECK(game.getPlayerYCoordinate() == maxCoordinate);
            REQUIRE_THROWS_AS(game.movePlayer(SOUTH), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == maxCoordinate);
            CHECK(game.getPlayerYCoordinate() == maxCoordinate);
        }

        SUBCASE("Edge Case X: 0, Y: max")
        {
            int maxCoordinate = game.getMapSize() - 1;

            for (int i = 0; i < maxCoordinate; i++)
            {
                game.movePlayer(SOUTH);
            }
            game.movePlayer(SOUTH); // Move to the max edge
            REQUIRE(game.getPlayerXCoordinate() == 0);
            REQUIRE(game.getPlayerYCoordinate() == maxCoordinate);

            REQUIRE_THROWS_AS(game.movePlayer(WEST), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == 0);
            CHECK(game.getPlayerYCoordinate() == maxCoordinate);
            REQUIRE_THROWS_AS(game.movePlayer(SOUTH), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == 0);
            CHECK(game.getPlayerYCoordinate() == maxCoordinate);
        }

        SUBCASE("Edge Case X: max, Y: 0")
        {
            int maxCoordinate = game.getMapSize() - 1;

            for (int i = 0; i < maxCoordinate; i++)
            {
                game.movePlayer(EAST);
            }
            game.movePlayer(EAST); // Move to the max edge
            REQUIRE(game.getPlayerXCoordinate() == maxCoordinate);
            REQUIRE(game.getPlayerYCoordinate() == 0);

            REQUIRE_THROWS_AS(game.movePlayer(EAST), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == maxCoordinate);
            CHECK(game.getPlayerYCoordinate() == 0);
            REQUIRE_THROWS_AS(game.movePlayer(NORTH), std::out_of_range);
            CHECK(game.getPlayerXCoordinate() == maxCoordinate);
            CHECK(game.getPlayerYCoordinate() == 0);
        }
}


    TEST_CASE("Enemy moves") {
        srand (0);
        Game game(STARTING_DIFFICULTY_LEVEL);
        REQUIRE(game.getEnemyXCoordinate() == 4);
        REQUIRE(game.getEnemyYCoordinate() == 4);

        game.enemyTurn();
        bool enemyMoved = (game.getEnemyXCoordinate() != 4 || game.getEnemyYCoordinate() != 4);
        CHECK(enemyMoved);

    }

    TEST_CASE("Enemy cannot go out of bound") {
        srand (0);
        Enemy enemy;
        REQUIRE(enemy.getEnemyXCoordinate() == 4);
        REQUIRE(enemy.getEnemyYCoordinate() == 4);
        int player_x = 0;
        int player_y = 0;
        SUBCASE("enemy does not move out of bounds when moving randomly") {
        for (int i = 0; i < 100; ++i) { // Run multiple times to check random movements
            enemy.moveEnemy(player_x, player_y, 0, MAP_SIZE);
            CHECK(enemy.getEnemyXCoordinate() >= 0);
            CHECK(enemy.getEnemyXCoordinate() < MAP_SIZE);
            CHECK(enemy.getEnemyYCoordinate() >= 0);
            CHECK(enemy.getEnemyYCoordinate() < MAP_SIZE);
            }
        }

         SUBCASE("enemy does not move out of bounds when chasing player") {
        // player coordinates at different edges of the map
        std::vector<std::pair<int, int>> player_positions = {
            {0, 0}, {0, MAP_SIZE - 1}, {MAP_SIZE - 1, 0}, {MAP_SIZE - 1, MAP_SIZE - 1}
        };

        for (const std::pair<int, int>& pos : player_positions) {
            player_x = pos.first;
            player_y = pos.second;

            for (int i = 0; i < 100; ++i) { // Run multiple times
                //Max difficulty, so always chases
                enemy.moveEnemy(player_x, player_y, MAX_DIFFICULTY_LEVEL, MAP_SIZE);
                CHECK(enemy.getEnemyXCoordinate() >= 0);
                CHECK(enemy.getEnemyXCoordinate() < MAP_SIZE);
                CHECK(enemy.getEnemyYCoordinate() >= 0);
                CHECK(enemy.getEnemyYCoordinate() < MAP_SIZE);
                if (enemy.enemyReachedPlayer(player_x, player_y))
                {
                    //if reached player, break (Game will end here, undefined behavior if player and enemy on same square)
                    break;
                }
            }
        }
    }

        //0 difficulty, so it is always random chance, does not chase player
    }

    TEST_CASE("Enemy chases player") {
        srand (0);
        Game game(MAX_DIFFICULTY_LEVEL);
        //Max difficulty, so enemy always chases player
        REQUIRE(game.getEnemyXCoordinate() == 4);
        REQUIRE(game.getEnemyYCoordinate() == 4);
        REQUIRE(game.getPlayerXCoordinate() == 0);
        REQUIRE(game.getPlayerYCoordinate() == 0);

        game.enemyTurn();
        bool enemyChasedPlayer = (game.getEnemyXCoordinate() == 3 || game.getEnemyYCoordinate() == 3);
        CHECK(enemyChasedPlayer);

    }

    TEST_CASE("Game is over when Enemy reaches player") {
        srand (0);
        Game game(STARTING_DIFFICULTY_LEVEL);
        int maxCoordinate = game.getMapSize()-1;

        for (int i = 0; i < maxCoordinate; i++)
        {
            game.movePlayer(EAST);
            game.movePlayer(SOUTH);
        }

        REQUIRE(game.getPlayerXCoordinate() == maxCoordinate);
        REQUIRE(game.getPlayerYCoordinate() == maxCoordinate);
        REQUIRE(game.getEnemyXCoordinate() == maxCoordinate);
        REQUIRE(game.getEnemyYCoordinate() == maxCoordinate);

        game.checkEvent();
        CHECK(game.isGameOver());

    }

    TEST_CASE("Player reaches danger field") {
        srand (0);
        Game game(STARTING_DIFFICULTY_LEVEL);
        //with seed of 0, there is a danger field at 0,1
        game.movePlayer(SOUTH);
        REQUIRE(game.getPlayerXCoordinate() == 0);
        REQUIRE(game.getPlayerYCoordinate() == 1);
        //with seed of 0, player solves first danger_field
        game.checkEvent();
        CHECK(game.getPlayerHealth() == STARTING_HEALTH);
        //with seed of 0, there is another danger field at 1,1; 2,1; 3,1 and 4,1
        //with seed 0, player solves first 4 challenges, but fails at the last one
        game.movePlayer(EAST);
        game.checkEvent();
        game.movePlayer(EAST);
        game.checkEvent();
        game.movePlayer(EAST);
        game.checkEvent();
        CHECK(game.getPlayerHealth() == STARTING_HEALTH-1);


    }

    TEST_CASE("Player reaches fountain") {
        srand (0);
        Game game(STARTING_DIFFICULTY_LEVEL);
        //with seed of 0, there is a fountain at 1,0

        game.movePlayer(EAST);
        REQUIRE(game.getPlayerXCoordinate() == 1);
        REQUIRE(game.getPlayerYCoordinate() == 0);

        SUBCASE("Player gets potion") {
            bool player_has_no_items_in_beginning = game.getPlayerItems(AGILITY_ITEM) == 0 && game.getPlayerItems(STRENGTH_ITEM) == 0 && game.getPlayerItems(INTELLIGENCE_ITEM) == 0;
            REQUIRE(player_has_no_items_in_beginning);
            game.checkEvent();
            bool player_got_an_item = game.getPlayerItems(AGILITY_ITEM)>0 || game.getPlayerItems(STRENGTH_ITEM)>0 || game.getPlayerItems(INTELLIGENCE_ITEM)>0;
            CHECK(player_got_an_item);
        }

        SUBCASE("Player already at full health"){
            CHECK(game.getPlayerHealth() == STARTING_HEALTH);
            game.checkEvent();
            CHECK(game.getPlayerHealth() == STARTING_HEALTH);
        }

        SUBCASE("Player has already lost health") {
            game.playerLosesHealth();
            REQUIRE(game.getPlayerHealth() < STARTING_HEALTH);
            int healthBefore = game.getPlayerHealth();
            game.checkEvent();
            CHECK(game.getPlayerHealth() == healthBefore + 1);

        }

    }



#else
int main()
{
    srand (time(NULL));    //set seed for random numbers
    Game game(STARTING_DIFFICULTY_LEVEL);
    while (1)
    {
        game.startOfRoundHouseKeeping();
        game.renderGame();
        try
        {
            game.movePlayer(game.getInput());
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
        catch(const std::invalid_argument& tmp)
        {
            std::cout << tmp.what() << std::endl;
        }
        catch(const std::runtime_error& tmp)
        {
            std::cout << tmp.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "Unknown Error\n";
        }



    }
    return 0;
}


#endif // TEST











