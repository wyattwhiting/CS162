#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Zoo.h"

using namespace std;

Zoo::Zoo()
{
    srand(time(NULL));
    //bank starts with $100000
    bank = 100000;
    foodBase = 80;

    //zoo starts empty at month 0
    timeElapsed = 0;

    numBears = 0;
    bearsBought = 0;

    numSeaLions = 0;
    seaLionsBought = 0;

    numTigers = 0;
    tigersBought = 0;
}

Zoo::~Zoo()
{
    //as long as arrays aren't empty, delete them
    if(numBears != 0) delete[] bears;
    if(numSeaLions != 0) delete[] seaLions;
    if(numTigers != 0) delete[] tigers;
}

void Zoo::play()
{
    do
    {
        printGamestate();
        ageAnimals();
        specialEvent();
        addRevenue();
        buyAnimal();
        payFood();
        updateFoodCost();
    } while (bank > 0 && userContinue());

    if(bank <= 0) cout << "Your financial incompetence has bankrupted your zoo. ";
    else cout << "We're sorry to see you go, and right when it was getting fun! ";
    cout << "Goodbye!" << endl;
}

void Zoo::ageAnimals()
{   
    //as long as arrays have an animal, loop and increase age of each
    for(int i = 0; i < numBears; i++) bears[i].incAge();
    for(int i = 0; i < numSeaLions; i++) seaLions[i].incAge();
    for(int i = 0; i < numTigers; i++) tigers[i].incAge();
}

void Zoo::specialEvent()
{   
    //generate random integer in [0, 3]

    //switch 
    switch(rand() % 4)
    {
        case 0:
            cout << "sickness" << endl;
            eventSick();
            break;
        case 1:
            cout << "birth" << endl;
            break;
        case 2: 
            cout << "attendance boom" << endl;
            eventBoom();
            break;
        case 3:
            cout << "No special event has occured." << endl;
            break;
        default:
            cout << "error" << endl;
            break;
    }
}

void Zoo::addRevenue()
{
    //revenue accumulator
    int revenue = 0;

    //add revenue from each animal
    for(int i = 0; i < numBears; i++)    revenue += bears[i].getRevenue();
    for(int i = 0; i < numSeaLions; i++) revenue += seaLions[i].getRevenue();
    for(int i = 0; i < numTigers; i++)   revenue += tigers[i].getRevenue();
    
    //report and add revenue
    cout << "Your montly revenue is $" << revenue << endl;
    bank += revenue;
}

void Zoo::buyAnimal()
{   
    //catch for no more purchases remaining
    if(bearsBought == 2 && seaLionsBought == 2 && tigersBought == 2)
    {
        cout << "You have already bought the maximum number of animals. No more may be purchased." << endl;
        return;
    }


    int userIn = 0;
    //prompt for animal type until valid input is taken
    do
    {
        cout << "Would you like to buy an animal this month? (1 = yes, 0 = no): ";
        cin >> userIn;
    } while (userIn != 0 && userIn != 1);

    //if new animals are wanted;
    if(userIn == 1)
    {   
        //get validated input
        printBuyOptions(userIn);

        cout << "You have ";

        if(userIn == 0)
        {
            addBlackBear(BlackBear(48)); 
            bearsBought++;
            numBears++;
            cout << 2 - bearsBought;
        } 
        if(userIn == 1)
        {
            addSeaLion(SeaLion(48)); 
            seaLionsBought++;
            numSeaLions++;
            cout << 2 - seaLionsBought;
        } 
        if(userIn == 2)
        {
            addTiger(Tiger(48)); 
            tigersBought++;
            numTigers++;
            cout << 2 - tigersBought;
        } 

        cout << " purchases of this species remaining." << endl;
    }   
}

void Zoo::printBuyOptions(int & userIn)
{
    //userIn will have number for species purchase with one available to purchase
    bool validPurchase = 1;
    do
    {
        do
        {
            cout << "[0] - Bear" << endl;
            cout << "[1] - Sea Lion" << endl;
            cout << "[2] - Tiger" << endl;
            cin >> userIn;
        } while (!(userIn == 0 || userIn == 1 || userIn == 2));

        if(userIn == 0 && bearsBought >= 2)
        {
            validPurchase = 0;
            cout << "Sorry, you have already purchased 2 bears. " << endl;
        } 
        if(userIn == 1 && seaLionsBought >= 2)
        {
            validPurchase = 0;
            cout << "Sorry, you have already purcahsed 2 sea lions. " << endl;
        }    
        if(userIn == 2 && tigersBought >= 2)
        {
            validPurchase = 0;
            cout << "Sorry, you have already purchased 2 tigers. " << endl;

        } 
    
    } while (!validPurchase);
    
    
}

void Zoo::payFood()
{
    int foodTotal = 0;
    for(int i = 0; i < numBears; i++)    foodTotal += foodBase * bears[i].getFoodCoeff();
    for(int i = 0; i < numSeaLions; i++) foodTotal += foodBase * seaLions[i].getFoodCoeff();
    for(int i = 0; i < numTigers; i++)   foodTotal += foodBase * tigers[i].getFoodCoeff();

    //report and deduct food costs
    cout << "You owe $" << foodTotal << " for animal feed this month." << endl;
    bank -= foodTotal;
}

void Zoo::updateFoodCost() { foodBase *= (((rand() % 41) + 80) / 100.0); }

void Zoo::printGamestate()
{
    timeElapsed++;
    cout << endl;
    cout << "*******************************" << endl;
    cout << "       Bank: $" << bank << endl;
    cout << "      Month: " << timeElapsed << endl << endl;
    cout << "Black Bears: " << numBears << endl;
    cout << "  Sea Lions: " << numSeaLions << endl;
    cout << "     Tigers: " << numTigers << endl;
    cout << "-------------------" << endl;
    cout << "      Total: " << numBears + numSeaLions + numTigers << endl;
    cout << "*******************************" << endl << endl;
}

void Zoo::eventSick()
{
    //catch for no animals
    if(numTigers + numSeaLions + numBears == 0)
    {
        cout << "There are no animals to get sick. You escaped this time..." << endl;
        return;
    }
    //steps for sickness
    int randAnimal = rand() % (numTigers + numSeaLions + numBears);
    int diseaseCost = 0;

    cout << "The unhealthy conditions in your zoo have lead to disease." << endl;
    cout << "A ";

    sickHelper(randAnimal, diseaseCost);

    cout << " has gotten sick. It will cost you $" << diseaseCost << endl;
    bank -= diseaseCost;

    if(bank < 0) cout << "You didn't have enough money to pay the vet fees. It died. F. " << endl; 

    
    
    //if()
    //compare to 
    return;
}

void Zoo::sickHelper(int randAnimal, int & diseaseCost)
{
    if(randAnimal < numBears)
    {
        if(bears[randAnimal].getAge() < 6) cout << "baby ";
        cout << "bear";
        diseaseCost = bears[randAnimal].getCost() / 2;
        if(diseaseCost > bank) removeBlackBear(randAnimal); 
    }

    //if in range of sea lions
    else if(randAnimal < numBears + numSeaLions)
    {
        if(seaLions[randAnimal - numBears].getAge() < 6) cout << "baby ";
        cout << "sea lion";
        diseaseCost = seaLions[randAnimal - numBears].getCost() / 2;
        if(diseaseCost > bank) removeSeaLion(randAnimal - numBears); 
    }

    //must be in range of tigers
    else
    {
        if(tigers[randAnimal - (numBears + numSeaLions)].getAge() < 6) cout << "baby ";
        cout << "tiger";
        diseaseCost = tigers[randAnimal - (numBears + numSeaLions)].getCost() / 2;
        if(diseaseCost > bank) removeTiger(randAnimal - (numBears + numSeaLions)); 
    }
}

void Zoo::eventBirth()
{
    //catch for no animals
    if(numBears + numSeaLions + numTigers == 0)
    {
        cout << "You have no animals that can give birth. " << endl;
        return;
    }


}

void Zoo::eventBoom()
{
    int boomBonus = 0;
    for(int i = 0; i < numSeaLions; i++)
    {
        boomBonus += ((rand() % 251) + 150);
    }
    bank += boomBonus;
    cout << "During the attendance boom, your " << numSeaLions;
    cout << " sea lions generated an extra $" << boomBonus;
    cout << " worth of revenue!" << endl;
}

void Zoo::addSeaLion(SeaLion newSeaLion)
{   
    //cout << "ADDING NEW SEA LION" << endl;
    //new array pointer with one more sea lion
    SeaLion * temp = new SeaLion[numSeaLions + 1];

    //copy existing members to new array pointer
    for(int i = 0; i < numSeaLions; i++) temp[i] = seaLions[i];

    //add new sea lion to end of array
    temp[numSeaLions] = newSeaLion;

    //as long as the old array had at least one member, delete
    if(numSeaLions != 0) delete[] seaLions;

    //assign new 
    seaLions = temp;
}

void Zoo::removeSeaLion(int index)
{
    //if there's only one animal
    if(numSeaLions == 1)
    {
        numSeaLions--; //reset count to 0
        delete[] seaLions; //delete array entirely
        return; //exit function
    }

    SeaLion * temp = new SeaLion[--numSeaLions];
    int writeIndex = 0;

    //copy over all members except one to remove
    for(int i = 0; i < numSeaLions; i++)
    {
        if(i != index) temp[writeIndex++] = seaLions[i];
    }

    delete[] seaLions;
    seaLions = temp;
}

void Zoo::addBlackBear(BlackBear newBlackBear)
{   
    //cout << "ADDING NEW BLACK BEAR" << endl;
    //new array pointer with one more sea lion
    BlackBear * temp = new BlackBear[numBears + 1];

    //copy existing members to new array pointer
    for(int i = 0; i < numBears; i++) temp[i] = bears[i];

    //add new sea lion to end of array
    temp[numBears] = newBlackBear;

    //as long as the old array had at least one member, delete
    if(numBears != 0) delete[] bears;

    //assign new 
    bears = temp;
}

void Zoo::removeBlackBear(int index)
{
    //if there's only one animal
    if(numBears == 1)
    {
        numBears--; //reset count to 0
        delete[] bears; //delete array entirely
        return; //exit function
    }

    BlackBear * temp = new BlackBear[--numBears];
    int writeIndex = 0;

    //copy over all members except one to remove
    for(int i = 0; i < numBears; i++)
    {
        if(i != index) temp[writeIndex++] = bears[i];
    }

    delete[] bears;
    bears = temp;
}

void Zoo::addTiger(Tiger newTiger)
{   
    //cout << "ADDING NEW TIGER" << endl;

    //new array pointer with one more sea lion
    Tiger * temp = new Tiger[numTigers + 1];

    //copy existing members to new array pointer
    for(int i = 0; i < numTigers; i++) temp[i] = tigers[i];

    //add new sea lion to end of array
    temp[numTigers] = newTiger;

    //as long as the old array had at least one member, delete
    if(numTigers != 0) delete[] tigers;

    //assign new 
    tigers = temp;
}

void Zoo::removeTiger(int index)
{
    //if there's only one animal
    if(numTigers == 1)
    {
        numTigers--; //reset count to 0
        delete[] tigers; //delete array entirely
        return; //exit function
    }

    Tiger * temp = new Tiger[--numTigers];
    int writeIndex = 0;

    //copy over all members except one to remove
    for(int i = 0; i < numTigers; i++)
    {
        if(i != index) temp[writeIndex++] = tigers[i];
    }

    delete[] tigers;
    tigers = temp;
}

bool Zoo::userContinue()
{
    int input;
    do
    {
        cout << "Would you like to continue to the next month? (0 = no, 1 = yes): ";
        cin >> input;
    } while (input != 0 && input != 1);
    
    return input;
}