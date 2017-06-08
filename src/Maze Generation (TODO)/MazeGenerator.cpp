//
// Created by luiscm on 5/4/17.
//

#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(ui inWidth, ui inHeight) :
    mWidth(inWidth), mHeight(inHeight)
{
    for (ui i = 0; i < mWidth; ++i) {
        for (ui j = 0; j < mHeight; ++j) {
            for (int k = -1; k < 2; ++k) {
                int rrow = i + k;

                for (int l = -1; l < 2; ++l) {
                    int rcol = j + l;

                    if (rcol >= 0 and rcol < mHeight and rrow >= 0 and rrow < mWidth)
                        1;
                }
            }
        }
    }
}

MazeGenerator::~MazeGenerator()
{}

Maze MazeGenerator::generate()
{
    return mMaze;
}

void MazeGenerator::display() const
{}
