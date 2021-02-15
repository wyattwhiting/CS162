#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "Heading.h"

using namespace std;

Heading::Heading()
{
    companyName = "ABC Industries";
    reportName = "Report";
}

Heading::Heading(string newComp, string newRepo)
{
    companyName = newComp;
    reportName = newRepo;
}

void Heading::printHeading1()
{
    cout << companyName << " " << reportName << endl;
}

void Heading::printHeading4()
{
    cout << "******************************" << endl << endl;

    cout << companyName << endl << endl;

    cout << reportName << endl << endl;

    cout << "******************************" << endl;
}