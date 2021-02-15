#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "Heading.h"

using namespace std;

int main()
{
    Heading heading1;
    Heading heading2("Pet Pals", "Payroll Report");

    heading1.printHeading1();
    heading1.printHeading4();

    cout << endl;

    heading2.printHeading1();
    heading2.printHeading4();


    return 0;
}