//
// Created by luiscm on 5/5/17.
//

#include <iostream>
#include <sstream>
#include "RSADigest.h"

RSADigest::RSADigest(uint64 n, uint64 e, uint64 d) : mN(n), mE(e), mD(d)
{}

RSADigest::~RSADigest()
{}

std::string RSADigest::encrypt(std::string inString)
{
    std::vector<uint64> _crypted_blocks{};

    std::vector<uint64> _blocks = _break_msg(inString);

    for (auto &&block : _blocks) {
        uint64 p = upow(block, mE) % mN;
        _crypted_blocks.push_back(p);
    }

    std::string _crypted_string = _make_crypt(_crypted_blocks);

    return _crypted_string;
}

std::string RSADigest::decrypt(std::string inCrypt)
{
    std::vector<uint64> _blocks{};

    std::vector<uint64> _crypted_blocks = _break_crypt(inCrypt);

    for (auto &&crypted_block : _crypted_blocks) {
        uint64 C = upow(crypted_block, mD) % mN;
        _blocks.push_back(C);
    }

    std::string _string = _make_msg(_blocks);

    return _string;
}



uint64 RSADigest::upow(uint64 p, uint64 e)
{
    uint64 res = 1;

    for (uint64 i = 0; i < e; ++i) {
        res = (res * p) % mN;
    }

    return res;
}

std::vector<uint64> RSADigest::_break_msg(std::string inString)
{
    std::vector<uint64> _blocks;
    std::string _Str = inString;

    for (auto &&str : _Str) {
        _blocks.push_back((uint64) str);
    }

    return _blocks;
}

std::string RSADigest::_make_msg(std::vector<uint64> inBlocks)
{
    std::string _str = "";

    for (auto &&block : inBlocks) {
        _str += (char) int(block) % 256;
    }

    return _str;
}

std::string RSADigest::_make_crypt(std::vector<uint64> inCrypt)
{
    std::string _crypt = "";

    for (int i = 0; i < inCrypt.size(); ++i) {
        _crypt += std::to_string(inCrypt[i]) + " ";
    }



    return _crypt;
}

std::vector<uint64> RSADigest::_break_crypt(std::string inCrypt)
{
    std::stringstream ss(inCrypt);
    std::vector<uint64> _blocks;
    std::string field;

    while (not ss.eof()) {
        if (ss >> field)
            _blocks.push_back(std::stoull(field));
    }

    return _blocks;
}
