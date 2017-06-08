//
// Created by luiscm on 5/5/17.
//

#include "NumbersSpeller.h"

NumbersSpeller::NumbersSpeller()
{}

NumbersSpeller::~NumbersSpeller()
{}

Word NumbersSpeller::spell(int inNum)
{
    Word spellable;

    int c = inNum % 1000;
    if (c < 20)
        spellable = spell_smalls(c);
    else
        spellable = spell_hundreds(c);

    if (inNum >= 1000)
        spellable = spell_thousands(inNum - (inNum % 100)) + " " + spellable;

    return spellable;
}

Word NumbersSpeller::spell_smalls(int inNum)
{
    if (inNum < 20)
        return smalls[inNum - 1];

    return "";
}

Word NumbersSpeller::spell_hundreds(int inNum)
{
    int c = inNum % 10;
    int num = (inNum % 100) / 10 - 1;
    int r = inNum / 100;


    return (r? smalls[r-1]+" hundread " : "") + (num? decades[num]+"-":"") + (c? smalls[c-1] : "");
}

Word NumbersSpeller::spell_thousands(int inNum)
{
    Word res = "";
    int c = inNum % 1000000000;
    int r = inNum / 1000000000;

    if ((!c) or (r)) {
        if (r < 20)
            res += spell_smalls(r) + thousandPowers[0];
        else if (r >= 20)
            res += spell_hundreds(r) + thousandPowers[0];
    }

    int s = c / 1000000;
    res += " "+(s>=20? spell_hundreds(s):spell_smalls(s)) + thousandPowers[1];

    s = (c / 1000) % 1000;
    res += " "+(s>=20? spell_hundreds(s):spell_smalls(s)) + thousandPowers[2];

    return res;
}
