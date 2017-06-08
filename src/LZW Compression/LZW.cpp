//
// Created by luiscm on 05/06/17.
//

#include <vector>
#include <iostream>
#include "LZW.h"

LZW::Encoder::Encoder()
{
    initialize();
}

LZW::Encoder::~Encoder()
{}

void LZW::Encoder::add(std::string inString)
{
    mDict[inString] = mNextCode;
    mNextCode++;
}

void LZW::Encoder::initialize()
{
    for (int i = 0; i < 256; ++i) {
        std::string init{};
        init += static_cast<char>(i);
        add(init);
    }
}

std::vector<uint> LZW::Encoder::compress(std::string inString)
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


LZW::Decoder::Decoder()
{
    initialize();
}

LZW::Decoder::~Decoder()
{}

void LZW::Decoder::add(std::string inString)
{
    mDict[mNextCode] = inString;
    mNextCode++;
}

void LZW::Decoder::initialize(void)
{
    for (int i = 0; i < 256; ++i) {
        std::string item{};
        item = static_cast<char>(i);
        add(item);
    }
}

std::string LZW::Decoder::decompress(std::vector<uint> inVector)
{
    std::string I{}, P{}, C{};
    uint cW, pW;

    cW = inVector.at(0);

    I += mDict.at(cW);

    for (int i = 1; i < inVector.size(); ++i) {
        pW = cW;
        cW = inVector.at(static_cast<uint>(i));

        if (mDict.count(cW) != 0) {
            I += mDict.at(cW);
            P = mDict.at(pW);
            C = mDict.at(cW)[0];
            add(P+C);
        } else {
            P = mDict.at(pW);
            C = P[0];
            I += P+C;
            add(P+C);
        }
    }

    return I;
}
