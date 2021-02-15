#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "shape.h"

class Circle : public Shape {
    private:
        float radius;
    public:
        float area() const;
        float getRadius();
        Circle();
        Circle(float);
};

#endif