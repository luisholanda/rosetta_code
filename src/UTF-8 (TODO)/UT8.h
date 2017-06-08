//
// Created by luiscm on 5/18/17.
//

#ifndef ROSETTA_CODE_UT8_H
#define ROSETTA_CODE_UT8_H


#include <vector>

namespace utf8
{
    std::vector<int> encode(int inChar);
    int decode(std::vector<int> inEnc);
};


#endif //ROSETTA_CODE_UT8_H
