//
// Created by luiscm on 05/06/17.
//

#ifndef ROSETTA_CODE_RIPEMD_H
#define ROSETTA_CODE_RIPEMD_H

#include <string>

namespace ripemd_160
{
    void hash(std::string inString);

    static const unsigned long h0 = 0x67452301UL;
    static const unsigned long h1 = 0xEFCDAB89UL;
    static const unsigned long h2 = 0x98BADCFEUL;
    static const unsigned long h3 = 0x10325476UL;
    static const unsigned long h4 = 0xC3D2E1F0UL;

}

#endif //ROSETTA_CODE_RIPEMD_H
