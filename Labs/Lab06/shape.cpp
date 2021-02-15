#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "shape.h"

using namespace std;

Shape::Shape()
{
    this->name = "unk";
    this->color = "unk";
}

Shape::Shape(string name, string color)
{
    this->name = name;
    this->color = color;
}

string Shape::getName() { return name; }

string Shape::getColor() { return color; }

float Shape::area() { return 0; }

void Shape::setName(string name) { this->name = name; }
void Shape::setColor(string color) { this->color = color; }