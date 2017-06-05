//
// Created by luiscm on 05/06/17.
//

#ifndef ROSETTA_CODE_GAME_H
#define ROSETTA_CODE_GAME_H

#include <vector>
#include "Cell.h"
#include "Ant.h"

using uint = unsigned int;

namespace Langton
{
    class Game
    {
    public:
        Game(uint inWidth, uint inHeight, Ant inAnt);
        virtual ~Game();

        void start(int inX, int inY);

    private:
        uint mHeight, mWidth, mIterations;
        std::vector<std::vector<Cell>> mBoard;
        Ant mAnt;
        uint mAntX, mAntY;

        bool makeStep();
        void displayBoard();
    };
}

#endif //ROSETTA_CODE_GAME_H
