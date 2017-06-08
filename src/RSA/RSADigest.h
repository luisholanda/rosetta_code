//
// Created by luiscm on 5/5/17.
//

#ifndef ROSETTA_CODE_RSADIGEST_H
#define ROSETTA_CODE_RSADIGEST_H


#include <string>
#include <vector>
#include <map>

using uint64 = unsigned long long int;

class RSADigest
{
public:
    RSADigest(uint64 n, uint64 e, uint64 d);
    virtual ~RSADigest();

    std::string encrypt(std::string inString);
    std::string decrypt(std::string inCrypt);

private:
    uint64 mN, mE, mD;

    std::vector<uint64> _break_msg(std::string inString);
    std::string _make_msg(std::vector<uint64> inBlocks);

    std::string _make_crypt(std::vector<uint64> inCrypt);
    std::vector<uint64> _break_crypt(std::string inCrypt);

    uint64 upow(uint64 p, uint64 e);


};


#endif //ROSETTA_CODE_RSADIGEST_H
