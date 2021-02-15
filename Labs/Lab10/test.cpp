#include "test.h"

using namespace std;

//car
int Car::getMaxSpeed() { return 0; }
        
void Car::setIdNum(string newNum) { idNum = newNum; }
void Car::setNumDoors(int num) { numDoors = num; }

string Car::getIdNum() { return idNum;}
int Car::getNumDoors() { return numDoors; }


//racecar
int RaceCar::getMaxSpeed()
{
    if(numDoors > 2) return 150; //greater than 2 doors
    return 200; //otherwise, less than or equal to 2
}

string RaceCar::getSponsor() {return sponsor;}
void RaceCar::setSponsor(string newS) {sponsor = newS;}
