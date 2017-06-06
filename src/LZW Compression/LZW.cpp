//
// Created by luiscm on 05/06/17.
//

#include <vector>
#include "LZW.h"

LZW::LZW::LZW()
{}

LZW::LZW::~LZW()
{}

void LZW::LZW::add(std::string inString)
{
    mDict[inString] = mNextCode;
    mNextCode++;
}

std::vector<unsigned int> LZW::LZW::compress(std::string inString)
{
    std::vector<unsigned int> I{};
    std::string buf{};

    for (char &&item : inString) {
        if (buf.empty() or mDict.at(buf+item))
        {
            buf += item;
        } else {
            I.push_back(mDict[buf]);
            add(buf+item);
            buf = item;
        }
    }

    if (not buf.empty())
        I.push_back(mDict[buf]);

    return I;
}

std::string LZW::LZW::decompress(std::string inString)
{

}
