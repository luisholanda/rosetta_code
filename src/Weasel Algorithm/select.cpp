//
// Created by luiscm on 5/5/17.
//

#include <cassert>
#include <iostream>
#include "select.h"

Select::Select()
{}

Select::~Select()
{}

int Select::fitness(std::string inMutation)
{
    assert(inMutation.length() == target.length());

    int _fitness = 0;

    for (int i = 0; i < inMutation.length(); ++i) {
        _fitness += (int) inMutation[i] == target[i];
    }

    return _fitness;
}

void Select::mutate(std::string inTarget, double inRate)
{
    target = inTarget;
    mRate = inRate;

//    Parent string
    std::string parent = "";
    int C = 100;

    for (int i = 0; i < target.length(); ++i) {
        parent += POSSIBLES[std::rand() % POSSIBLES.length()];
    }

    int iterations = 0;

    while (iterations++ < maxIter and parent != target)
    {
        std::pair<std::string, int> maxFit("", 0);
        for (int i = 0; i < C; ++i) {
            std::string mString = mutate_string(parent);
            int fit = fitness(mString);

            if (fit > maxFit.second) {
                maxFit.first = mString;
                maxFit.second = fit;
            }
        }

        parent = maxFit.first;

        std::cout << "Generation " << iterations
                  << ": " << parent << std::endl;
    }
}

std::string Select::mutate_string(const std::string& inString)
{
    std::string _new(inString);

    for (int i = 0; i < _new.length(); ++i) {
        if (_new[i] != target[i]) {
            if (std::rand() / (double) RAND_MAX < mRate)
                _new[i] = POSSIBLES[std::rand() % POSSIBLES.length()];
        }
    }

    return _new;
}
