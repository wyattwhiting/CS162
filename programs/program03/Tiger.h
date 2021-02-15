/******************************************************
** File: Tiger.h
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: tiger class header
******************************************************/
#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Animal.h"

using namespace std;

class Tiger : public Animal
{
    public:
        //big 3(4)
        Tiger();
        Tiger(int);
        ~Tiger();
        Tiger(const Tiger &);
};

#endif