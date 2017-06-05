//
// Created by luiscm on 05/06/17.
//

#include "src/Langton's ant/Game.h"

int main()
{
    Langton::Ant ant;
    Langton::Game game(100, 100, ant);

    game.start(40, 40);
}