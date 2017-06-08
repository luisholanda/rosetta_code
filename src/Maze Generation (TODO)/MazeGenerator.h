//
// Created by luiscm on 5/4/17.
//

#ifndef ROSETTA_CODE_MAZEGENERATOR_H
#define ROSETTA_CODE_MAZEGENERATOR_H

#include <set>
#include <map>

using ui = unsigned int;
using Maze = std::map<std::pair<ui , ui>, std::set<std::pair<ui , ui>>>;

class MazeGenerator
{
public:
    MazeGenerator(ui inWidth, ui inHeight);
    virtual ~MazeGenerator();

    virtual Maze generate();
    virtual void display() const;

private:
    ui mWidth, mHeight;
    Maze mMaze;
};


#endif //ROSETTA_CODE_MAZEGENERATOR_H
