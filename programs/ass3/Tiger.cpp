/******************************************************
** File: Tiger.cpp
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: tiger class implementation
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Tiger.h"

using namespace std;

/*******************************************************
 * Function: Tiger::Tiger()
 * Description: tiger default constructor
 * Parameters: none
 * Pre-Conditions: tiger does not exist
 * Post-Conditions: tiger exists with default values
 *******************************************************/
Tiger::Tiger()
{
    //start with default values
    age = 0;
    cost = 15000;
    numBabies = 3;
    revenueCoeff = 0.1;
    foodCoeff = 1;
}

/*******************************************************
 * Function: Tiger::Tiger(int startAge)
 * Description: tiger constructor overload
 * Parameters: startAge - starting age for tiger
 * Pre-Conditions: none
 * Post-Conditions: tiger is instantiated with age startAge
 *******************************************************/
Tiger::Tiger(int startAge)
{
    //start with default values, except with starting age startAge
    age = startAge;
    cost = 15000;
    numBabies = 3;
    revenueCoeff = 0.1;
    foodCoeff = 5;
}

/*******************************************************
 * Function: Tiger::~Tiger()
 * Description: tiger class destructor
 * Parameters: none
 * Pre-Conditions: tiger exists
 * Post-Conditions: tiger no longer exists
 *******************************************************/
Tiger::~Tiger() {}

/*******************************************************
 * Function: Tiger::Tiger(const Tiger & newTiger)
 * Description: tiger copy constructor
 * Parameters: newTiger - tiger to copy
 * Pre-Conditions: one
 * Post-Conditions: tiger is constructed with traits of newTiger
 *******************************************************/
Tiger::Tiger(const Tiger & newTiger)
{
    //just copy everything over
    age = newTiger.age;
    cost = newTiger.cost;
    numBabies = newTiger.numBabies;
    revenueCoeff = newTiger.revenueCoeff;
    foodCoeff = newTiger.foodCoeff;
}