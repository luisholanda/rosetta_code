//
// Created by luiscm on 5/4/17.
//

#include <vector>
#include <iostream>
#include "harshad.h"

int sumOfDigits(int inNum) {
    int i = inNum, sum = 0;
    
    while (i) {
        sum += i % 10;
        i = i / 10;
    }
    
    return sum;
}

bool isHarshad(int inNum) {
    return !(inNum % sumOfDigits(inNum));
}

void harshad() {
    std::vector<int> sequence;

    int found = 0, i = 1;

    while (found < 20) {
        if (isHarshad(i)) {
            sequence.push_back(i);
            found++;
        }

        i++;
    }

    std::cout << "First twenty Harshad numbers: " << std::endl;

    for (auto &&item : sequence) {
        std::cout << item << " ";
    }
    std::cout << std::endl << std::endl;

    i = 1000;

    while (not isHarshad(++i));

    std::cout << "First Harshad number greater than 1000: " << i << std::endl;
}
