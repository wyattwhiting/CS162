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
        //big 3
        SeaLion();
        SeaLion(int);
        ~SeaLion();
        SeaLion(const SeaLion &);
};

#endif