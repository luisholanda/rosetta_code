//
// Created by luiscm on 05/06/17.
//

#ifndef ROSETTA_CODE_CELL_H
#define ROSETTA_CODE_CELL_H

#include "Langton.h"

namespace Langton
{
    class Cell
    {
    public:
        Cell();
        virtual ~Cell();

        void print();

        void setColor(color inColor);
        color getColor();

        void invertColor();

    private:
        color mColor;
    };
}

#endif //ROSETTA_CODE_CELL_H
