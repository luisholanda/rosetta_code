//
// Created by luiscm on 05/06/17.
//

#include <vector>
#include <iostream>
#include "LZW.h"

LZW::LZW::LZW()
{
    initialize();
}

LZW::LZW::~LZW()
{}

void LZW::LZW::add(std::string inString)
{
    mDict[inString] = mNextCode;
    mNextCode++;
}

void LZW::LZW::initialize()
{
    for (int i = 0; i < 256; ++i) {
        std::string init{};
        init += static_cast<char>(i);
        add(init);
    }
}

void print(std::map<std::string, unsigned int> map)
{
    for (auto &&item : map) {
        if (item.first != "")
            std::cout << item.first << ", " << item.second << std::endl;
    }

    std::cout << std::endl;
}

std::vector<unsigned int> LZW::LZW::compress(std::string inString)
{
    std::vector<unsigned int> I{};
    std::string buf{""};

    for (auto&& item: inString) {
        if (mDict.count(buf+item) != 0) {
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

std::string LZW::LZW::decompress(std::vector<unsigned int> inString)
{
    std::string I{};

    return I;
}
