#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <stdexcept>
#include <exception>

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle() : Shape("rectangle", "orange")
{
    this->width = -1;
    this->height = -1;
}

Rectangle::Rectangle(float w, float h) : Shape("rectangle", "red")
{
    this->width = w;
    this->height = h;
    try
    {
        if(w * h == 0) throw invalid_argument("Invalid constructor argument");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "creating default object instead..." << endl;
        this->width = -1;
        this->height = -1;
    }
    
    
}

float Rectangle::area() const { return this->width * this -> height; }
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