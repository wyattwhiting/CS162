#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal
{
    protected:
        int age;
        int cost;
        int numBabies;
        float revenueCoeff;
        int foodCoeff;

    public:
        //Big 3

        Animal();
        Animal(int);
        ~Animal();
        Animal(const Animal &);
        Animal & operator=(Animal);



        //getters

        int getAge();
        int getCost();
        int getNumBabies();
        int getRevenue();
        int getFoodCoeff();



        //setters

        int incAge();

};

#endif