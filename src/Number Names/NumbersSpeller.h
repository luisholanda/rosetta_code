//
// Created by luiscm on 5/5/17.
//

#ifndef ROSETTA_CODE_NUMBERSSPELLER_H
#define ROSETTA_CODE_NUMBERSSPELLER_H

#include <string>
#include <vector>

using Word = std::string;
using Words = std::vector<Word>;

class NumbersSpeller
{
public:
    NumbersSpeller();
    virtual ~NumbersSpeller();

    Word spell(int inNum);

private:
    Word spell_smalls(int inNum);
    Word spell_hundreds(int inNum);
    Word spell_thousands(int inNum);

    Words smalls{
            "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
            "nineteen"
    };
    Words decades{
            "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    Words thousandPowers {
        " billion", " million", " thousand", ""
    };

};


#endif //ROSETTA_CODE_NUMBERSSPELLER_H
