//
// Created by luiscm on 5/5/17.
//

#include "LCG.h"

LCG::LCG(ulli seed) : mState(seed)
{}

LCG::~LCG()
{}

ulli LCG::rand()
{
    return next();
}

ulli LCG::next()
{
    mState = (A*mState + C) % MOD;
    return mState;
}
