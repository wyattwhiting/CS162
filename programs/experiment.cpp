#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int start = 80;
    srand(time(NULL));
    
    for(int i = 0; i < 500; i++)
    {
        start *= (((rand() % 41) + 80) / 100.0);
        cout << start << endl;
    }
    return 0;
}