#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "square.h"

using namespace std;

Square::Square() : Rectangle(0,0)
{
    setName("square");
    setColor("magenta");

}

Square::Square(float dim) : Rectangle(dim, dim)
{
    setName("square");
    setColor("cyan/magenta");
}

