//
// Created by luiscm on 5/5/17.
//

#ifndef ROSETTA_CODE_SHANNON_H
#define ROSETTA_CODE_SHANNON_H

#include <string>
#include <map>
#include <cmath>

double shannon_entropy(std::string X) {

    std::map<char , unsigned int> _freq;
    double N;

    double _entropy = 0;

    N = X.size();

//    Get frequency of characters
    for (char item : X) {
        _freq[item] = 0;
    }

    for (char item : X) {
        _freq[item]++;
    }

//    Calculates the entropy
    for (std::pair<const char , unsigned int> freq : _freq) {
        _entropy += freq.second * log2(freq.second/N);
    }

    _entropy /= N;

    return - _entropy;
}

#endif //ROSETTA_CODE_SHANNON_H
