#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;

void print_shape_info(Shape * s)
{
    cout << endl;
    cout << "Name: " << s->getName() << endl;
    cout << "Color: " << s->getColor() << endl;
    cout << "Area: " << s->area() << endl;
}


int main()
{   
    Shape shape1 = Shape();
    Rectangle rec1 = Rectangle(1.0, 10.0);
    Square square1 = Square(44.0);
    Circle circle1 = Circle(22.1);
    Rectangle rec2 = Rectangle(0,0);

    Shape * arr[] = {&shape1, &rec1, &square1, &circle1, &rec2};

    for(int i = 0; i < 5; i++)
    {
        print_shape_info(arr[i]);
    }

    //it finally works! if parent virtual function is 'const' then child MUST
    //be as well. 

    
    Circle circ = Circle(0);
    Square test = Square(0);

    return 0;
}