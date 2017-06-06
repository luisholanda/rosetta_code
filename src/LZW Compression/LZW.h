//
// Created by luiscm on 05/06/17.
//

#ifndef ROSETTA_CODE_LZW_H
#define ROSETTA_CODE_LZW_H

#include <string>
#include <map>

namespace LZW
{
    class LZW
    {
    public:
        LZW();
        virtual ~LZW();

        std::vector<unsigned int> compress(std::string inString);
        std::string decompress(std::string inString);

    private:
        std::map<std::string, unsigned int> mDict;
        unsigned int mNextCode = 0;

        void add(std::string inString);
    };
}

#endif //ROSETTA_CODE_LZW_H
