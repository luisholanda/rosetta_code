//
// Created by luiscm on 05/06/17.
//

#include "Ant.h"

Langton::Ant::Ant():
        mDirection(TOP)
{}

Langton::Ant::~Ant()
{}

Langton::direction Langton::Ant::getDirection()
{
    return mDirection;
}

void Langton::Ant::setDirection(Langton::direction inDirection)
{
    mDirection = inDirection;
}

void Langton::Ant::updateDirection(color inColor)
{
    switch (mDirection) {
        case LEFT:
            mDirection = inColor == WHITE ? TOP : BOTTOM;
            break;
        case TOP:
            mDirection = inColor == WHITE ? RIGHT : LEFT;
            break;
        case RIGHT:
            mDirection = inColor == WHITE ? BOTTOM : TOP;
            break;
        case BOTTOM:
            mDirection = inColor == WHITE ? LEFT : RIGHT;
            break;
    }
}
