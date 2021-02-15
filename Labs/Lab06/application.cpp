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

int main()
{
    Shape shape1;
    Shape shape2("rhombus", "blue");

    Rectangle rec1;
    Rectangle rec2(10, 20);

    Circle circ1;
    Circle circ2(15.3);

    Square square1;
    Square square2(13.2);

    cout << "Shape1: " << shape1.getName() << " " << shape1.getColor() << endl;
    cout << "Shape2: " << shape2.getName() << " " << shape2.getColor() << endl << endl;

    cout << "rec1: " << rec1.getName() << " " << rec1.getColor() << " " << rec1.area() << endl;
    cout << "rec2: " << rec2.getName() << " " << rec2.getColor() << " " << rec2.area() << endl << endl;

    cout << "circ1: " << circ1.getName() << " " << circ1.getColor() << " " << circ1.area() << endl;
    cout << "circ2: " << circ2.getName() << " " << circ2.getColor() << " " << circ2.area() << endl << endl;

    cout << "square1: " << square1.getName() << " " << square1.getColor() << " " << square1.area() << endl;
    cout << "square2: " << square2.getName() << " " << square2.getColor() << " " << square2.area() << endl;

    cout << (square1 > rec2) << endl;
    cout << (rec1 < square2) << endl;
    
    return 0;
}