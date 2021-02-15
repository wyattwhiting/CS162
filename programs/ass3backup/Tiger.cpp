#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Tiger.h"

using namespace std;

Tiger::Tiger()
{
    age = 0;
    cost = 15000;
    numBabies = 3;
    revenueCoeff = 0.1;
    foodCoeff = 1;
}

Tiger::Tiger(int startAge)
{
    age = startAge;
    cost = 15000;
    numBabies = 3;
    revenueCoeff = 0.1;
    foodCoeff = 5;
}

Tiger::~Tiger() {}

Tiger::Tiger(const Tiger & newTiger)
{
    //just copy everything over
    age = newTiger.age;
    cost = newTiger.cost;
    numBabies = newTiger.numBabies;
    revenueCoeff = newTiger.revenueCoeff;
    foodCoeff = newTiger.foodCoeff;
}