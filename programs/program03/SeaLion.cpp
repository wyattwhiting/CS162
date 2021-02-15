/******************************************************
** File: SeaLion.cpp
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: sea lion class implementation
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "SeaLion.h"

using namespace std;

/*******************************************************
 * Function: SeaLion::SeaLion()
 * Description: sea lion default constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sea lion constructed with default values
 *******************************************************/
SeaLion::SeaLion()
{
    //start with default values
    age = 0;
    cost = 800;
    numBabies = 1;
    revenueCoeff = 0.2;
    foodCoeff = 1;
}

/*******************************************************
 * Function: SeaLion::SeaLion(int startAge)
 * Description: overloaded sea lion constructor
 * Parameters: startAge - starting age for sea lion
 * Pre-Conditions: none
 * Post-Conditions: sea lion instantiated with default values,
 *                  and age = startAge
 *******************************************************/
SeaLion::SeaLion(int startAge)
{
    //same as defualt, but start with age startAge
    age = startAge;
    cost = 800;
    numBabies = 1;
    revenueCoeff = 0.2;
    foodCoeff = 1;

}

/*******************************************************
 * Function: SeaLion::~SeaLion()
 * Description: sea lion destructor
 * Parameters: none
 * Pre-Conditions: sea lion exists
 * Post-Conditions: sea lion destroyed
 *******************************************************/
SeaLion::~SeaLion() {}

/*******************************************************
 * Function: SeaLion::SeaLion(const SeaLion & newSeaLion)
 * Description: sea lion copy constructor
 * Parameters: newSeaLion - sea lion to copy
 * Pre-Conditions: none
 * Post-Conditions: new sea lion constructed and assumes
 *                  traits of newSeaLion
 *******************************************************/
SeaLion::SeaLion(const SeaLion & newSeaLion)
{
    //just copy everything over
    age = newSeaLion.age;
    cost = newSeaLion.cost;
    numBabies = newSeaLion.numBabies;
    revenueCoeff = newSeaLion.revenueCoeff;
    foodCoeff = newSeaLion.foodCoeff;
}