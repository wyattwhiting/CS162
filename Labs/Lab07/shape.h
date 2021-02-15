#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;

class Shape {
    private:
        string name;
        string color;
    public:
        virtual float area() const;
        Shape();
        Shape(string, string);
        string getName();
        string getColor();
        void setName(string);
        void setColor(string);
      
};


#endif