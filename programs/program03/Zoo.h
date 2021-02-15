/******************************************************
** File: Zoo.h
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: zoo class header
******************************************************/
#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "BlackBear.h"
#include "SeaLion.h"
#include "Tiger.h"

using namespace std;

class Zoo
{
    private:
        int timeElapsed;
        int foodBase;
        int bank;

        BlackBear * bears;
        int numBears;
        int bearsBought;

        SeaLion * seaLions;
        int numSeaLions;
        int seaLionsBought;

        Tiger * tigers;
        int numTigers;
        int tigersBought;

        //a bunch of function prototypes for all the functions of a zoo
        void ageAnimals();
        void specialEvent();
        void addRevenue();
        void buyAnimal();
        void buyAnimalHelper(int);
        void printBuyOptions(int &);
        void payFood();
        void updateFoodCost();
        void printGamestate();
        void eventSick();
        void sickHelper(int, int &);
        void eventBirth();
        void birthHelper(int);
        bool hasAdult(int);
        void eventBoom();
        void addSeaLion(SeaLion);
        void removeSeaLion(int);
        void addBlackBear(BlackBear);
        void removeBlackBear(int);
        void addTiger(Tiger);
        void removeTiger(int);
        bool userContinue();

    public:
        //don't need assignment overload or copy constructor
        Zoo();
        ~Zoo();

        //other functions
        void play();
};

#endif