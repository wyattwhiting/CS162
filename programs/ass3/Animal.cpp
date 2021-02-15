/******************************************************
** File: Animal.cpp
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: Animal class implementation
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Animal.h"

using namespace std;

/*******************************************************
 * Function: Animal::Animal()
 * Description: default animal constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: animal object initialized with 
 *                  strange values
 *******************************************************/
Animal::Animal()
{   
    //there should never be an Animal object, so give strange values
    age = -1;
    cost = -1;
    numBabies = -1;
    revenueCoeff = -1;
    foodCoeff = -1;
}

/*******************************************************
 * Function: Animal::Animal(int startAge)
 * Description: overloaded animal constructor
 * Parameters: startAge - starting age of animal
 * Pre-Conditions: none
 * Post-Conditions: animal is initialized
 *******************************************************/
Animal::Animal(int startAge)
{   
    //this class of animal should never exist
    age = startAge;
    cost = -1;
    numBabies = -1;
    revenueCoeff = -1;
    foodCoeff = -1;
}

/*******************************************************
 * Function: Animal::~Animal()
 * Description: animal destructor   
 * Parameters: none
 * Pre-Conditions: animal exists
 * Post-Conditions: animal no longer exists
 *******************************************************/
Animal::~Animal() {}

/*******************************************************
 * Function: Animal::Animal(const Animal & newAnimal) 
 * Description: animal copy constructor 
 * Parameters: newAnimal - animal to be copied
 * Pre-Conditions: new animal doesn't not exist
 * Post-Conditions: new animal exists and assumes traits of newAnimal
 *******************************************************/
Animal::Animal(const Animal & newAnimal) 
{   
    //just copy everything over
    age = newAnimal.age;
    cost = newAnimal.cost;
    numBabies = newAnimal.numBabies;
    revenueCoeff = newAnimal.revenueCoeff;
    foodCoeff = newAnimal.foodCoeff;
}

/*******************************************************
 * Function: Animal & Animal::operator=(Animal newAnimal)
 * Description: animal operator= overload
 * Parameters: newAnimal - animal to be copied
 * Pre-Conditions: animal exists
 * Post-Conditions: animal assumes properties of newAnimal
 *******************************************************/
Animal & Animal::operator=(Animal newAnimal)
{
    age = newAnimal.age;
    cost = newAnimal.cost;
    numBabies = newAnimal.numBabies;
    revenueCoeff = newAnimal.revenueCoeff;
    foodCoeff = newAnimal.foodCoeff;
    return *this;
}

/*******************************************************
 * Function: int Animal::getAge()
 * Description: age accessor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int Animal::getAge() { return age; }

/*******************************************************
 * Function: int Animal::getCost()
 * Description: cost accessor 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int Animal::getCost() { return cost; }

/*******************************************************
 * Function: int Animal::getNumBabies()
 * Description: num babies accessor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int Animal::getNumBabies() { return numBabies; }

/*******************************************************
 * Function: int Animal::getRevenue() 
 * Description: reveue accessor
 * Parameters: none
 * Pre-Conditions: none 
 * Post-Conditions: none. object remains unchanged
 *******************************************************/
int Animal::getRevenue() 
{
    //standard revenue
    int revenue = (int)(cost * revenueCoeff);

    //young animals double revenue
    if(age < 6) return (revenue * 2);

    //else it's just base
    return revenue;
}

/*******************************************************
 * Function: int Animal::getFoodCoeff()
 * Description: getter for food cost multiplier
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int Animal::getFoodCoeff() { return foodCoeff; }

/*******************************************************
 * Function: int Animal::incAge()
 * Description: age incrementer
 * Parameters: none
 * Pre-Conditions: age has value n
 * Post-Conditions: age has value (n + 1)
 *******************************************************/
int Animal::incAge() { age += 1; }
