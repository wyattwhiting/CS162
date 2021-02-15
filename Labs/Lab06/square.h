#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "rectangle.h"

using namespace std;

class Square : public Rectangle {
    public:
        Square();
        Square(float);
};

#endif