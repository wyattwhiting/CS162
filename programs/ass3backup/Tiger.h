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
        //big 3
        Tiger();
        Tiger(int);
        ~Tiger();
        Tiger(const Tiger &);
};

#endif