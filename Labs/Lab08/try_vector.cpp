#include "./vector.h"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v;         //Our vector class
    std::vector<int> stdv; //Standard vector


    //Compare operation of our vector to std
    v.push_back(23);
    stdv.push_back(23);

    //copy constrctors
    vector<int> vcpy = v;
    std::vector<int> stdvcpy = stdv;

    //assignment operator
    vector<int> vcpy2;
    std::vector<int> stdvcpy2;
    vcpy2 = vcpy;
    stdvcpy2 = stdvcpy;



    cout << "Our vector size: " << v.size() << endl;
    cout << "STL vector size: " << stdv.size() << endl;

    cout << "Copy of our vector size: " << vcpy.size() << endl;
    cout << "Copy of STL vector size: " << stdvcpy.size() << endl;

    cout << "Copy of our vector size with =: " << vcpy2.size() << endl;
    cout << "Copy of STL vector size with =: " << stdvcpy2.size() << endl;

    vcpy.push_back(15);
    cout << "Pushed back 15 onto vector copy. Element: " << vcpy[1] << endl;
    vcpy2.push_back(45);
    cout << "Pushed back 45 onto second copy of vector. vcpy(2).at(1) = " << vcpy2.at(1) << endl;


    return 0;
}