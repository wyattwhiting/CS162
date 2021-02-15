#ifndef HEADING_H
#define HEADING_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;

class Heading
{
    private:
        string companyName;
        string reportName;
    public:
        Heading();
        Heading(string, string);


        void printHeading1();
        void printHeading4();

};

#endif
