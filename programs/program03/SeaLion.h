/******************************************************
** File: SeaLion.h
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: sea lion class header
******************************************************/
#ifndef SEALION_H
#define SEALION_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Animal.h"

using namespace std;

class SeaLion : public Animal
{
    public:
        //big 3(4)
        SeaLion();
        SeaLion(int);
        ~SeaLion();
        SeaLion(const SeaLion &);
};

#endif