//
// Created by luiscm on 05/06/17.
//

#ifndef ROSETTA_CODE_ANT_H
#define ROSETTA_CODE_ANT_H

#include "Langton.h"

namespace Langton
{
    class Ant
    {
    public:
        Ant();
        virtual ~Ant();

        direction getDirection();
        void updateDirection(color inColor);

    private:
        void setDirection(direction inDirection);
        direction mDirection;
    };
}

#endif //ROSETTA_CODE_ANT_H
