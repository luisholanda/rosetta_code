//
// Created by luiscm on 05/06/17.
//

#include <iostream>
#include "Cell.h"

Langton::Cell::Cell():
        mColor(WHITE)
{}

Langton::Cell::~Cell()
{}

void Langton::Cell::setColor(Langton::color inColor)
{
    mColor = inColor;
}

Langton::color Langton::Cell::getColor()
{
    return mColor;
}

void Langton::Cell::print()
{
    static const char black = '*';
    static const char white = ' ';

    std::cout << (mColor == WHITE ? white : black);
}

void Langton::Cell::invertColor()
{
    switch (mColor){
        case BLACK:
            mColor = WHITE;
        case WHITE:
            mColor = BLACK;
    }
}
