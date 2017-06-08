//
// Created by luiscm on 05/06/17.
//

#ifndef ROSETTA_CODE_LZW_H
#define ROSETTA_CODE_LZW_H

#include <string>
#include <map>
#include <vector>

namespace LZW
{
    using uint = unsigned int;

    class Encoder
    {
    public:
        Encoder();
        virtual ~Encoder();

        std::vector<uint> compress(std::string inString);

    private:
        std::map<std::string, uint> mDict;
        uint mNextCode = 0;

        void add(std::string inString);
        void initialize(void);
    };

    class Decoder
    {
    public:
        Decoder();
        virtual ~Decoder();

        std::string decompress(std::vector<uint> inVector);

    private:
        std::map<uint, std::string> mDict;
        uint mNextCode = 0;

        void add(std::string inString);
        void initialize(void);
    };
}

#endif //ROSETTA_CODE_LZW_H
