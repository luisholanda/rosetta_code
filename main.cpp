//
// Created by luiscm on 05/06/17.
//

#include <iostream>
#include "src/LZW Compression/LZW.h"

int main()
{
    LZW::Encoder lzwe;

    auto v = lzwe.compress("TOBEORNOTTOBEORTOBEORNOT");

    for (auto &&item :v) {
        std::cout << item << " ";
    }

    std::cout << std::endl;

    LZW::Decoder lzwd;

    std::cout << lzwd.decompress(v) << std::endl;

}