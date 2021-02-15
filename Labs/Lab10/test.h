#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;

class Car 
{
    protected:
        string idNum;
        int numDoors;

    public:
        int getMaxSpeed();
        
        void setIdNum(string);
        void setNumDoors(int);

        string getIdNum();
        int getNumDoors();
};

class RaceCar : public Car
{
    private:
        string sponsor;

    public:
        int getMaxSpeed();
        string getSponsor();
        void setSponsor(string);
};