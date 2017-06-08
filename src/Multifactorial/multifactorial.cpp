//
// Created by luiscm on 5/5/17.
//

#include "multifactorial.h"

ull multifactorial(int n, int degree)
{
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;

    return n*multifactorial(n-degree, degree);
}
