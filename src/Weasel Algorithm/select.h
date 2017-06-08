//
// Created by luiscm on 5/5/17.
//

#ifndef ROSETTA_CODE_SELECT_H
#define ROSETTA_CODE_SELECT_H

#include <string>

class Select
{
public:
    Select();
    virtual ~Select();

    virtual void mutate(std::string inTarget, double inRate);
private:
    std::string target;
    double mRate;
    int maxIter = 1000;

    std::string POSSIBLES = "ABCDEFGHIJKLMNOPQRSTUVXWYZ ";

    int fitness(std::string inMutation);
    std::string mutate_string(const std::string& inString);
};


#endif //ROSETTA_CODE_SELECT_H
