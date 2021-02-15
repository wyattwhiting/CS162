#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle() : Shape("rectangle", "orange")
{
    this->width = 0;
    this->height = 0;
}

Rectangle::Rectangle(float w, float h) : Shape("rectangle", "red")
{
    this->width = w;
    this->height = h;
}

float Rectangle::area() const { return width * height; }
float Rectangle::getWidth() {return width;}
float Rectangle::getHeight() { return height; }

bool Rectangle::operator>(const Rectangle & rec)
{
    return area() > rec.area();
}

bool Rectangle::operator<(const Rectangle & rec)
{
    return area() < rec.area();
}