//
// Created by luiscm on 05/06/17.
//

#include <iostream>
#include "src/LZW Compression/LZW.h"

int main()
{
    LZW::LZW lzw;

    auto v = lzw.compress("TOBEORNOTTOBEORTOBEORNOT");

    for (auto &&item :v) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
}