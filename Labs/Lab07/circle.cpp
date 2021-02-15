#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <exception>
#include <stdexcept>

#include "circle.h"

Circle::Circle() : Shape("circle", "black")
{
    this->radius = 0.0;
}

Circle::Circle(float radius) : Shape("circle", "purple")
{
    this->radius = radius;
    try
    {
        if(radius == 0) throw invalid_argument("zero radius entered");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "setting to default radius" << endl;
        this->radius = 1;
    }
    
}

float Circle::getRadius() { return radius; }

float Circle::area() const
{
    return 3.14 * this->radius * this->radius; //pi r^2
}