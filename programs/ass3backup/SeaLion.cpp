#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "SeaLion.h"

using namespace std;

SeaLion::SeaLion()
{
    age = 0;
    cost = 800;
    numBabies = 1;
    revenueCoeff = 0.2;
    foodCoeff = 1;
}

SeaLion::SeaLion(int startAge)
{
    age = startAge;
    cost = 800;
    numBabies = 1;
    revenueCoeff = 0.2;
    foodCoeff = 1;

}

SeaLion::~SeaLion() {}

SeaLion::SeaLion(const SeaLion & newSeaLion)
{
    //just copy everything over
    age = newSeaLion.age;
    cost = newSeaLion.cost;
    numBabies = newSeaLion.numBabies;
    revenueCoeff = newSeaLion.revenueCoeff;
    foodCoeff = newSeaLion.foodCoeff;
}