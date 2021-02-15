#include "test.h"

using namespace std;

int main()
{
	Car car1;
    RaceCar * rcptr;

    string str;
    int doors;
    cout << "Enter an ID for the car: ";
    cin >> str;
    cout << "Enter a number of doors: ";
    cin >> doors;
    car1.setIdNum(str);
    car1.setNumDoors(doors);

    cout << "Max speed: " << car1.getMaxSpeed() << endl;

    int numRC;
    cout << "Enter number of racecars: ";
    cin >> numRC;

    rcptr = new RaceCar[numRC];

    for(int i = 0; i < numRC; i++)
    {
        int num;
        string str;
        string spon; 

        cout << "ID: ";
        cin >> str;
        cout << "Doors: ";
        cin >> num;
        cout << "Sponsor: ";
        cin >> spon;
        rcptr[i].setIdNum(str);
        rcptr[i].setNumDoors(num);
        rcptr[i].setSponsor(spon);

    }

    for(int i = 0; i < numRC; i++)
        cout << "Max speed for RaceCar " << i << ": " << rcptr[i].getMaxSpeed() << endl;

    delete[] rcptr;


	return 0;
}
