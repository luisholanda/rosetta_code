//
// Created by luiscm on 05/06/17.
//

#include "RIPEMD.h"

namespace ripemd_160
{
    unl f(int j, unl x, unl y, unl z)
    {
        if (0 <= j and j <= 15)
            return x ^ y ^ z;
        else if (16 <= j and j <= 31)
            return (x & y) | (~x & z);
        else if (32 <= j and j <= 47)
            return (x | ~y) ^ z;
        else if (48 <= j and j <= 63)
            return (x & y) | (y & ~z);
        else
            return x ^(y | ~z);
    }

    unl K(int j)
    {
        if (0 <= j and j <= 15)
            return 0x00000000;
        else if (16 <= j and j <= 31)
            return 0x5A827999;
        else if (32 <= j and j <= 47)
            return 0x6ED9EBA1;
        else if (48 <= j and j <= 63)
            return 0x8F1BBCDC;
        else
            return 0xA953FD4E;
    }

    unl K_(int j)
    {
        if (0 <= j and j <= 15)
            return 0x50A28BE6;
        else if (16 <= j and j <= 31)
            return 0x5C4DD124;
        else if (32 <= j and j <= 47)
            return 0x6D703EF3;
        else if (48 <= j and j <= 63)
            return 0x7A6D76E9;
        else
            return 0x00000000;
    }

    std::string rmd160(std::string inString)
    {
        std::string _hash{};

        std::string padded = padding(inString);



        return _hash;
    }

    std::string padding(std::string inString)
    {
        std::string padded = inString + static_cast<char>(128);

        int left = padded.length() % 64;

        for (size_t i = 0; i < left; i++) {
            padded += static_cast<char>(0);
        }



        padded += static_cast<char>(inString.length());
        return padded;
    }
}
