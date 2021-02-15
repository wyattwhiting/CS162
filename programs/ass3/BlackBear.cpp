/******************************************************
** File: BlackBear.cpp
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: black bear class implmentation
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "BlackBear.h"

using namespace std;

/*******************************************************
 * Function: BlackBear::BlackBear()
 * Description: black bear object default constructor   
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: black bear is initilized with proper values
 *******************************************************/
BlackBear::BlackBear()
{
    age = 0;
    cost = 6000;
    numBabies = 2;
    revenueCoeff = 0.1;
    foodCoeff = 3;
}

/*******************************************************
 * Function: BlackBear::BlackBear(int startAge)
 * Description: black bear overloaded constructor
 * Parameters: startAge - starting age for bear
 * Pre-Conditions: none
 * Post-Conditions: black bear is initilaized with 
 *                  age = startAge
 *******************************************************/
BlackBear::BlackBear(int startAge)
{
    //same as default, but start with age startAge
    age = startAge;
    cost = 6000;
    numBabies = 2;
    revenueCoeff = 0.1;
    foodCoeff = 3;
}

/*******************************************************
 * Function: BlackBear::~BlackBear()
 * Description: black bear destructor   
 * Parameters: none
 * Pre-Conditions: bear exists
 * Post-Conditions: bear no longer exists
 *******************************************************/
BlackBear::~BlackBear() {}

/*******************************************************
 * Function: BlackBear::BlackBear(const BlackBear & newBlackBear)
 * Description: black bear copy constructor
 * Parameters: newBlackBear - black bear to copy
 * Pre-Conditions: black bear does not exist
 * Post-Conditions: black bear exists and assumes properties
 *                  of newBlackBear
 *******************************************************/
BlackBear::BlackBear(const BlackBear & newBlackBear)
{
    //just copy everything over
    age = newBlackBear.age;
    cost = newBlackBear.cost;
    numBabies = newBlackBear.numBabies;
    revenueCoeff = newBlackBear.revenueCoeff;
    foodCoeff = newBlackBear.foodCoeff;
}