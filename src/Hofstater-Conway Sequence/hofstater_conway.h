//
// Created by luiscm on 5/5/17.
//

#ifndef ROSETTA_CODE_HOFSTATER_CONWAY_H
#define ROSETTA_CODE_HOFSTATER_CONWAY_H

#include <cmath>
#include <iostream>
#include <map>

int hc_sequence(int n) {
    static std::map<int, int> _cache;

    if (_cache[n])
        return _cache[n];

    if (n == 1 or n == 2) {
        _cache[n] = 1;
        return 1;
    }

    int a_n_1 = hc_sequence(n-1);
    _cache[n] = hc_sequence(a_n_1) + hc_sequence(n - a_n_1);

    return _cache[n];
}

void hc_main() {
    std::map<int , int> values;

    double pow20 = pow(2, 20);

    for (int i = 1; i <= pow20; ++i) {
        values[i] = hc_sequence(i);
        std::cout << "Term " << i << ": " << values[i]
                  << ", maxima: " << values[i] / (double) i << std::endl;
    }

    int p = 1;
    for (int j = 1; j < pow20; ++j) {
        if (values[j] / (double) j > 0.55 and j > p)
            p = j;
    }

    std::cout << p << std::endl;
}

#endif //ROSETTA_CODE_HOFSTATER_CONWAY_H
