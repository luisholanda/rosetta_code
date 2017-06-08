//
// Created by luiscm on 5/4/17.
//

#ifndef ROSETTA_CODE_HAILSTONE_H
#define ROSETTA_CODE_HAILSTONE_H

#include <vector>
#include <iostream>

using ull = unsigned int;

class Hailstone
{
public:
    Hailstone();
    virtual ~Hailstone();

    int task();

    virtual std::vector<ull> sequenceFor(ull inNum);
    virtual ull lengthFor(ull inNum);
    virtual std::pair<ull, ull> greater();

    static const ull kN = 100000;
};



#endif //ROSETTA_CODE_HAILSTONE_H
