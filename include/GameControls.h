#ifndef GAMECONTROLS_H
#define GAMECONTROLS_H

#include <string.h>



class GameControls
{
    public:
        GameControls();
        //Getters
        char getInput() const;
        //other functions
        void askInput();

    private:
        char input_ = 'x';
};

#endif // GAMECONTROLS_H
