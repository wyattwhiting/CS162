#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "BlackBear.h"

using namespace std;

BlackBear::BlackBear()
{
    age = 0;
    cost = 6000;
    numBabies = 2;
    revenueCoeff = 0.1;
    foodCoeff = 3;
}

BlackBear::BlackBear(int startAge)
{
    age = startAge;
    cost = 6000;
    numBabies = 2;
    revenueCoeff = 0.1;
    foodCoeff = 3;
}

BlackBear::~BlackBear() {}

BlackBear::BlackBear(const BlackBear & newBlackBear)
{
    //just copy everything over
    age = newBlackBear.age;
    cost = newBlackBear.cost;
    numBabies = newBlackBear.numBabies;
    revenueCoeff = newBlackBear.revenueCoeff;
    foodCoeff = newBlackBear.foodCoeff;
}