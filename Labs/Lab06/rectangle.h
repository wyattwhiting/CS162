#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "shape.h"

using namespace std;

class Rectangle : public Shape {
    private:
        float width;
        float height;
    public:
        float area() const;
        float getWidth();
        float getHeight();
        Rectangle();
        Rectangle(float, float);

        bool operator>(const Rectangle &);
        bool operator<(const Rectangle &);
};

#endif