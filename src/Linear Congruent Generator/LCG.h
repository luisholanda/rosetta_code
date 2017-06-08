//
// Created by luiscm on 5/5/17.
//

#ifndef ROSETTA_CODE_LCG_H
#define ROSETTA_CODE_LCG_H

#include <cmath>

/*
 * BSD formula
 */

using ulli = unsigned long int;
class LCG
{
public:
    LCG(ulli seed);
    virtual ~LCG();

    virtual ulli rand();

private:
    ulli next();

    ulli mState;
    static const ulli MOD = (ulli) pow(2, 31);
    static const ulli A = 1103515245LL;
    static const ulli C = 12345LL;
};


#endif //ROSETTA_CODE_LCG_H
