#ifndef GAMEOTHER_H
#define GAMEOTHER_H
#include <iostream>


class GameOther
{
    public:
        explicit GameOther(int difficulty_level);
        void setSeed();
        void gameMessage(std::string game_message);
        void errorMessage(std::string error_message);
        void nextScreen();
        void incrementDifficultyLevel();
        //Getters
        int getDifficultyLevel() const;
        virtual ~GameOther();


    protected:

    private:
    int difficulty_level_;   //determines number of enemies and how aware they are of the player
};

#endif // GAMEOTHER_H
