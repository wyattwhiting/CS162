/******************************************************
** File: main.cpp
** Author: Wyatt Whiting
** Date: 2020-12-02
** Description: driver file for linked list project
******************************************************/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

/*******************************************************
 * Function: bool usrRepeat()
 * Description: asks if user wants to loop program
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
bool usrRepeat()
{
    char in;
    do
    {
        cout << endl << "Would you like to run again? (y/n):";
        cin >> in;
    } while(in != 'y' && in != 'n');

    if(in == 'y') return 1;
    else return 0;
    
}

/*******************************************************
 * Function: int main()
 * Description: main function for program
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int main()
{
    do 
    {
        //create linked list
        LinkedList list = LinkedList();

        //input buckets
        char charIn = 'y';
        int in;

        //get array elements from user
        do 
        {
            cout << "Please enter a number: ";
            cin >> in;
            list.pushBack(in);

            cout << "Would you like to enter another number? (y/n): ";
            cin >> charIn;
        } while (charIn != 'n');
    
        //let user choose sort type
        do
        {
            cout << "Sort ascending or descending? (a/d): ";
            cin >> charIn;
            cout << charIn << endl;
        } while (charIn != 'a' && charIn != 'd');

        //sort based on user choice
        if(charIn == 'a') list.sortAscending();
        else list.sortDescending();

        //sorted linked list
        cout << "Your linked list is: " << endl;
        list.print();

        //display number of primes
        cout << "Your list had " << list.countPrimes() << " primes. " << endl;

    } while(usrRepeat());
    
    //return 0 and terminate program
    return 0;
}