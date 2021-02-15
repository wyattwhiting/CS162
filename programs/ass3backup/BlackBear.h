#ifndef BLACKBEAR_H
#define BLACKBEAR_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Animal.h"

using namespace std;

class BlackBear : public Animal
{
    public:
        //big 3
        BlackBear();
        BlackBear(int);
        ~BlackBear();
        BlackBear(const BlackBear &);

};

#endif