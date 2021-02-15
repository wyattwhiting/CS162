#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Animal.h"

using namespace std;

Animal::Animal()
{   
    //there should never be an Animal object, so give strange values
    age = -1;
    cost = -1;
    numBabies = -1;
    revenueCoeff = -1;
    foodCoeff = -1;
}

Animal::Animal(int startAge)
{   
    //this class of animal should never exist
    age = startAge;
    cost = -1;
    numBabies = -1;
    revenueCoeff = -1;
    foodCoeff = -1;
}

Animal::~Animal() {}

Animal::Animal(const Animal & newAnimal) 
{   
    //just copy everything over
    age = newAnimal.age;
    cost = newAnimal.cost;
    numBabies = newAnimal.numBabies;
    revenueCoeff = newAnimal.revenueCoeff;
    foodCoeff = newAnimal.foodCoeff;
}

Animal & Animal::operator=(Animal newAnimal)
{
    age = newAnimal.age;
    cost = newAnimal.cost;
    numBabies = newAnimal.numBabies;
    revenueCoeff = newAnimal.revenueCoeff;
    foodCoeff = newAnimal.foodCoeff;
    return *this;
}

//getters
int Animal::getAge() { return age; }
int Animal::getCost() { return cost; }
int Animal::getNumBabies() { return numBabies; }

int Animal::getRevenue() 
{
    //standard revenue
    int revenue = (int)(cost * revenueCoeff);

    //young animals double revenue
    if(age < 6) return (revenue * 2);

    //else it's just base
    return revenue;
}

int Animal::getFoodCoeff() { return foodCoeff; }

//setters
int Animal::incAge() { age += 1; }
