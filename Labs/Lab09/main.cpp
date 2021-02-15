#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void selectSort(int len, int * arr)
{
    int i, j, min;

    for(int i = 0; i < len - 1; i++)
    {
        min = i;

        //find index of minimum value ahead of current check position
        for(j = i + 1; j < len; j++)
            if(arr[j] < arr[min]) 
                min = j;

        //swap elements
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

bool isPrime(int n)
{
    if(n == 4) return false;
    for(int i = 2; i < n / 2; i++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    srand(time(NULL));
    int in = -1;
    cout << "Enter an integer: ";

    while(in < 1 || in > 25)
    {   
        cin >> in;
    }
    
    //1d dynamic array
    int * arr = new int[in];
    int * cpy = new int[in];

    //fill with random numbers
    for(int i = 0; i < in; ++i)
    {   
        //populate
        arr[i] = (rand() % 100) + 1;

        //print
        cout << arr[i] << endl;

        //make copy
        cpy[i] = arr[i];

    } 

    //selection sort
    selectSort(in, cpy);

    cout << endl;

    //print sorted array
    for(int i = 0; i < in; i++) cout << cpy[i] << endl;

    //print out primes
    cout << "Primes" << endl;
    for(int i = 0; i < in; i++)
        if(isPrime(cpy[i])) cout << cpy[i] << endl;
    



    delete[] arr;
    return 0;
}