//
// Created by luiscm on 5/18/17.
//

#include <iostream>
#include "UT8.h"


std::vector<int> utf8::encode(int inChar)
{
    std::vector<int> _encoding;

    do
    {
        int c = inChar % 256;
        _encoding.push_back(c);

        inChar /= 256;
    } while (inChar % 256);

    return _encoding;
}

int ::utf8::decode(std::vector<int> inEnc)
{
    return 0;
}
