//
// Created by luiscm on 5/4/17.
//

#include "Hailstone.h"

Hailstone::Hailstone()
{}

Hailstone::~Hailstone()
{}

std::vector<ull> Hailstone::sequenceFor(ull inNum)
{
    std::vector<ull> hail;
    ull i = inNum;

//    Generate the sequence
    while (i != 1) {
        hail.push_back(i);
        i = i & 1 ? (3 * i) + 1 : i / 2;
    }

//    Add one to the sequence
    hail.push_back(i);

    return hail;
}

ull Hailstone::lengthFor(ull inNum)
{
    ull i = inNum, length = 1;

    while (i != 1) {
        length++;
        i = i & 1 ? (3 * i) + 1 : i / 2;
    }

    return length;
}

std::pair<ull, ull> Hailstone::greater()
{
    std::pair<ull, ull> g(0, 0);

    for (ull i = 1; i <= kN; ++i) {
        ull length = lengthFor(i);
        if (length > g.second) {
            g.first = i;
            g.second = length;
        }
    }

    return g;
}

int Hailstone::task()
{
    std::cout << "Starting tasks.." << std::endl;

    std::cout << "Sequence for 27:" << std::endl;
    std::vector<ull> seq = sequenceFor(27);

    for (auto &&item : seq) {
        std::cout << item << " ";
    }

    std::cout << std::endl;

    ull length = lengthFor(27);
    std::cout << "Length: " << length << std::endl;

    std::pair<ull, ull> g = greater();
    std::cout << "Greater: " << g.first << ", " << g.second << std::endl;

    return 0;
}
