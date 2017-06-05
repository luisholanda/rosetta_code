//
// Created by luiscm on 05/06/17.
//

#include <iostream>
#include "Game.h"

Langton::Game::Game(uint inWidth, uint inHeight, Ant inAnt):
    mWidth(inWidth), mHeight(inHeight),
    mIterations(0), mAnt(inAnt)
{
    mBoard.resize(inHeight);

    for (auto &&board : mBoard) {
        board.resize(inWidth);
    }
}

Langton::Game::~Game()
{}

void Langton::Game::start(int inX, int inY)
{
    mAntX = static_cast<uint>(inX);
    mAntY = static_cast<uint>(inY);

    while (true)
    {
        displayBoard();

        if (makeStep())
            mIterations++;
        else break;
    }
}

bool Langton::Game::makeStep()
{
    Cell& cell = mBoard[mAntX][mAntY];

    mAnt.updateDirection(cell.getColor());
    cell.invertColor();

    switch (mAnt.getDirection()) {
        case LEFT:
            mAntX--; break;
        case TOP:
            mAntY--; break;
        case RIGHT:
            mAntX++; break;
        case BOTTOM:
            mAntY++; break;
    }

    return not (mAntX < 0 or mAntX >= mWidth or mAntY < 0 or mAntY >= mHeight);
}

void Langton::Game::displayBoard()
{
    for (auto &&item : mBoard) {
        for (auto &&cell : item) {
            cell.print();
        }

        std::cout << std::endl;
    }

    std::cout << mIterations << std::endl;
}
