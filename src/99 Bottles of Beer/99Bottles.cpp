//
// Created by luiscm on 05/06/17.
//

#include <iostream>
#include "99Bottles.h"

void BeerBottles::main()
{
    for (int i = 99; i > 0; --i) {
        step(i);
        std::cout << std::endl << std::endl;
    }

    std::cout << "No more bottles of beer on the wall" << std::endl;
    std::cout << "No more bottles of beer" << std::endl;
    std::cout << "Go to the store and buy some more" << std::endl;
    std::cout << "99 bottles of beer on the wall" << std::endl;
}

void BeerBottles::step(int inBottles)
{
    std::cout << inBottles << " ";
    if (inBottles != 1)
        std::cout << "bottles of beer on the wall" << std::endl;
    else std::cout << "bottle of beer on the wall" << std::endl;

    std::cout << inBottles << " ";
    if (inBottles != 1)
        std::cout << "bottles of beer" << std::endl;
    else std::cout << "bottle of beer" << std::endl;

    std::cout << "Take one down, pass it around" << std:: endl;

    inBottles--;

    if (inBottles > 0) {
        std::cout << inBottles << " ";
        if (inBottles != 1)
            std::cout << "bottles of beer on the wall" << std::endl;
        else std::cout << "bottle of beer on the wall" << std::endl;
    } else {
        std::cout << "No more bottles of beer on the wall" << std::endl;
    }
}
