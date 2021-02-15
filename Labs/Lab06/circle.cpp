#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "circle.h"

Circle::Circle() : Shape("circle", "black")
{
    this->radius = 0.0;
}

Circle::Circle(float radius) : Shape("circle", "purple")
{
    this->radius = radius;
}

float Circle::getRadius() { return radius; }

float Circle::area()
{
    return 3.14 * this->radius * this->radius; //pi r^2
}