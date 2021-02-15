/******************************************************
** File: Zoo.cpp
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: zoo class implementation
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Zoo.h"

using namespace std;

/*******************************************************
 * Function: Zoo::Zoo()
 * Description: zoo constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: zoo is instantiated according to 
 *                  assignment requirements
 *******************************************************/
Zoo::Zoo()
{
    //seed random numbers for whole game
    srand(time(NULL));

    //bank starts with $100000
    bank = 100000;
    foodBase = 80;

    //zoo starts empty at month 0
    timeElapsed = 0;

    //animal stats
    numBears = 0;
    bearsBought = 0;

    numSeaLions = 0;
    seaLionsBought = 0;

    numTigers = 0;
    tigersBought = 0;
}

/*******************************************************
 * Function: Zoo::~Zoo()
 * Description: zoo destructor  
 * Parameters: none
 * Pre-Conditions: dynamic animal arrays have members
 * Post-Conditions: dynamic animal arrays are deleted
 *******************************************************/
Zoo::~Zoo()
{
    //as long as arrays aren't empty, delete them
    if(numBears != 0) delete[] bears;
    if(numSeaLions != 0) delete[] seaLions;
    if(numTigers != 0) delete[] tigers;
}

/*******************************************************
 * Function: void Zoo::play()
 * Description: main game loop
 * Parameters: none
 * Pre-Conditions: game has not started
 * Post-Conditions: game has ended
 *******************************************************/
void Zoo::play()
{
    //game loop. Continue while player has money and wants to continue
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

    //if player ends game bankrupted
    if(bank <= 0) cout << "Your financial incompetence has bankrupted your zoo. ";
    else cout << "We're sorry to see you go, and right when it was getting fun! ";
    cout << "Goodbye!" << endl;
}

/*******************************************************
 * Function: void Zoo::ageAnimals()
 * Description: ages all the animals in the zoo by 1 month
 * Parameters: none
 * Pre-Conditions: all animals have age n_i
 * Post-Conditions: all animals have age (n_i + 1)
 *******************************************************/
void Zoo::ageAnimals()
{   
    //as long as arrays have an animal, loop and increase age of each
    for(int i = 0; i < numBears; i++) bears[i].incAge();
    for(int i = 0; i < numSeaLions; i++) seaLions[i].incAge();
    for(int i = 0; i < numTigers; i++) tigers[i].incAge();
}

/*******************************************************
 * Function: void Zoo::specialEvent()
 * Description: chooses and executes a monthly special event
 * Parameters: none
 * Pre-Conditions: animals have been aged
 * Post-Conditions: special event has been executed
 *******************************************************/
void Zoo::specialEvent()
{   
    //generate random integer in [0, 3]
    cout << "Monthly special event: ";

    //switch statement for choosing event. Should be self-evident as to which does which
    switch(rand() % 4)
    {
        case 0:
            cout << "sickness" << endl;
            eventSick();
            break;
        case 1:
            cout << "birth" << endl;
            eventBirth();
            break;
        case 2: 
            cout << "attendance boom" << endl;
            eventBoom();
            break;
        case 3:
            cout << "no special event has occured." << endl;
            break;
        default:
            cout << "error" << endl;
            break;
    }
}

/*******************************************************
 * Function: void Zoo::addRevenue()
 * Description: calculates revenue and adds tob ank
 * Parameters: none
 * Pre-Conditions: special event has occured
 * Post-Conditions: bank is updated with appropriate revenue
 *******************************************************/
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

/*******************************************************
 * Function: void Zoo::buyAnimal()
 * Description: allows user to purchase animals for zoo
 * Parameters: none
 * Pre-Conditions: revenue has been added for the month
 * Post-Conditions: if possible and user desires, adult
 *                  animal of selected type is added to     
 *                  the appropriate exhibit
 *******************************************************/
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
        //get validated input. updates userIn with species choice too
        printBuyOptions(userIn);

        //start print
        cout << "You have ";

        //helper function call
        buyAnimalHelper(userIn);

        //finish the printing
        cout << " purchases of this species remaining." << endl;
    }   
}

/*******************************************************
 * Function: void Zoo::buyAnimalHelper(int userIn)
 * Description: adds appropriate animal and updates stats
 * Parameters: userIn - represents species bought by user
 * Pre-Conditions: user must have purchases of desired species  
 *                 remaining
 * Post-Conditions: appropriate animal of age 4y is added
 *                  to corresponding exhibit
 *******************************************************/
void Zoo::buyAnimalHelper(int userIn)
{
    //switch statement. Adds appropriate animal and updates stats
    switch(userIn)
    {
        case 0: //black bears
            addBlackBear(BlackBear(48)); 
            bearsBought++;
            cout << 2 - bearsBought;
            break;
        case 1: //sea lions
            addSeaLion(SeaLion(48)); 
            seaLionsBought++;
            cout << 2 - seaLionsBought;
            break;
        case 2: //tigers
            addTiger(Tiger(48)); 
            tigersBought++;
            cout << 2 - tigersBought;
            break;
        default: //should never get here
            cout << "ERROR" << endl;
            break;
    }
}

/*******************************************************
 * Function: void Zoo::printBuyOptions(int & userIn)
 * Description: shows user which animal they can buy,   
 *              disallows purchase if max has already   
 *              been purchased
 * Parameters: userIn - userInput variable, represents  
 *             species to be bought
 * Pre-Conditions: animals must be available to purchase
 * Post-Conditions: userIn is updated with purchase choice
 *                  which is guaranteed to be valid
 *******************************************************/
void Zoo::printBuyOptions(int & userIn)
{
    //userIn will have number for species purchase with one available to purchase
    bool validPurchase;
    do
    {
        validPurchase = 1; //reset purchase validity

        //print options
        do
        {
            cout << "[0] - Bear" << endl;
            cout << "[1] - Sea Lion" << endl;
            cout << "[2] - Tiger" << endl;
            cin >> userIn;
        } while (!(userIn == 0 || userIn == 1 || userIn == 2));

        //check for if species have already hit max purchases
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
    
    } while (!validPurchase); //continue while selection isn't valid
}

/*******************************************************
 * Function: void Zoo::payFood()
 * Description: pays the food cost for the upcoming month
 * Parameters: none
 * Pre-Conditions: bank has money in it
 * Post-Conditions: bank has total for food deducted
 *******************************************************/
void Zoo::payFood()
{
    //food price accumulator
    int foodTotal = 0;

    //accumulate price for each animal in zoo
    for(int i = 0; i < numBears; i++)    foodTotal += foodBase * bears[i].getFoodCoeff();
    for(int i = 0; i < numSeaLions; i++) foodTotal += foodBase * seaLions[i].getFoodCoeff();
    for(int i = 0; i < numTigers; i++)   foodTotal += foodBase * tigers[i].getFoodCoeff();

    //report and deduct food costs
    cout << "You owe $" << foodTotal << " for animal feed this month." << endl;
    bank -= foodTotal;
}

/*******************************************************
 * Function: void Zoo::updateFoodCost()
 * Description: updates the base food cost for the month
 * Parameters: none
 * Pre-Conditions: foodBase has monthly base food cost
 * Post-Conditions: foodBase is multiplied by random value
 *                  in [0.8, 1.2] with uniform probability
 *******************************************************/
void Zoo::updateFoodCost() { foodBase *= (((rand() % 41) + 80) / 100.0); }

/*******************************************************
 * Function: void Zoo::printGamestate()
 * Description: prints current gamestate
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none - gamestate is unchanged
 *******************************************************/
void Zoo::printGamestate()
{
    //increment elapsed time
    timeElapsed++;

    //print summary of zoo
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

/*******************************************************
 * Function: void Zoo::eventSick()
 * Description: chooses random animal to get sick
 * Parameters: none
 * Pre-Conditions: Animal must be in zoo
 * Post-Conditions: cost of vet fees is deducted from   
 *                  bank. If funds are not available, 
 *                  animal is killed. 
 *******************************************************/
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

    //print some stuff
    cout << "The unhealthy conditions in your zoo have lead to disease." << endl;
    cout << "A ";

    //call helper function. Kills the animal if they don't have money
    sickHelper(randAnimal, diseaseCost);

    //more printing
    cout << " has gotten sick. It will cost you $" << diseaseCost << endl;
    
    //deduct how much the player owes
    bank -= diseaseCost;

    //if they're broke, tell them so
    if(bank < 0) cout << "You didn't have enough money to pay the vet fees. It died. F. " << endl;
    return;
}

/*******************************************************
 * Function: void Zoo::sickHelper(int randAnimal, int & diseaseCost)
 * Description: helper function for sickness function
 * Parameters: randAnimal - global index of sick animal
 *             diseaseCost - cost of vet treatment
 * Pre-Conditions: randAnimal has global index of sick animal
 * Post-Conditions: diseaseCost is updated with cost of treatment
 *******************************************************/
void Zoo::sickHelper(int randAnimal, int & diseaseCost)
{
    //if in range of bears
    if(randAnimal < numBears)
    {
        //print stuff, assign cost of treatment
        diseaseCost = bears[randAnimal].getCost() / 2;
        if(bears[randAnimal].getAge() < 6) //fix for baby
        {
            cout << "baby ";
            diseaseCost *= 2;
        } 
        cout << "bear";
        
        if(diseaseCost > bank) removeBlackBear(randAnimal); 
    }

    //if in range of sea lions
    else if(randAnimal < numBears + numSeaLions)
    {   
        //print stuff, assign cost of treatment
        diseaseCost = seaLions[randAnimal - numBears].getCost() / 2;
        if(seaLions[randAnimal - numBears].getAge() < 6) //fix for baby
        {
            cout << "baby ";
            diseaseCost *= 2;
        } 
        cout << "sea lion";
        
        if(diseaseCost > bank) removeSeaLion(randAnimal - numBears); 
    }

    //if it gets, here, it must be in range of tigers
    else
    {
        //print stuff, assign cost of treatment
        diseaseCost = tigers[randAnimal - (numBears + numSeaLions)].getCost() / 2;
        if(tigers[randAnimal - (numBears + numSeaLions)].getAge() < 6) //fix for baby
        {
           cout << "baby "; 
           diseaseCost *= 2;
        } 
        cout << "tiger";
        if(diseaseCost > bank) removeTiger(randAnimal - (numBears + numSeaLions)); 
    }
}

/*******************************************************
 * Function: void Zoo::eventBirth()
 * Description: birth event 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: randomly chosen species that has at 
 *                  least one adult has babies added
 *******************************************************/
void Zoo::eventBirth()
{
    //catch for no animals
    if(numBears + numSeaLions + numTigers == 0)
    {
        cout << "You have no animals that can give birth. " << endl;
        return;
    }

    //find species which has adult
    int species;
    do
    {
        species = rand() % 3;
        
    } while (!hasAdult(species));

    //now the selected species has an adult
    cout << "A ";

    //call helper function
    birthHelper(species);

    //finish printing
    cout << " babies!" << endl;
}

/*******************************************************
 * Function: void Zoo::birthHelper(int species)
 * Description: helper function for birth event
 * Parameters: species - int to respresent chosen species
 * Pre-Conditions: none
 * Post-Conditions: approparite number of babies of chosen
 *                  species added to exhibit
 *******************************************************/
void Zoo::birthHelper(int species)
{   
    //species switch statement
    switch(species)
    {
        case 0: //bear - add appropriate number of babies
            for(int i = 0; i < bears[0].getNumBabies(); i++) addBlackBear(BlackBear(0));
            cout << "bear has given birth to " << bears[0].getNumBabies();
            break;
        case 1: //sea lion - add appropriate number of babies
            for(int i = 0; i < seaLions[0].getNumBabies(); i++) addSeaLion(SeaLion(0));
            cout << "sea lion has given birth to " << seaLions[0].getNumBabies();
            break;
        case 2: //tiger -- add appropriate number of babies
            for(int i = 0; i < tigers[0].getNumBabies(); i++) addTiger(Tiger(0));
            cout << "tiger has given birth to " << tigers[0].getNumBabies();
        default: //if default runs, there was a major error
            cout << "ERROR";
            break;
    } 
}

/*******************************************************
 * Function: bool Zoo::hasAdult(int species)
 * Description: determines if given species has adult member
 * Parameters: species - represents species to check
 * Pre-Conditions: none
 * Post-Conditions: returns if given species has adult member
 *******************************************************/
bool Zoo::hasAdult(int species)
{
    //switch statement for species
    switch(species)
    {
        case 0: //bears
            //loop to find adult
            for(int i = 0; i < numBears; i++) if(bears[i].getAge() >= 48) return true;
            return false;
            break;
        case 1: //sea lions
            //loop to find adult
            for(int i = 0; i < numSeaLions; i++) if(seaLions[i].getAge() >= 48) return true;
            return false;
            break;
        case 2: //tigers
            //loop to find adult
            for(int i = 0; i < numTigers; i++) if(tigers[i].getAge() >= 48) return true;
            return false;
            break;
        default: //default catch. Should never get here.
            cout << "ERROR" << endl;
            break;
    }    
}

/*******************************************************
 * Function: void Zoo::eventBoom()
 * Description: calculates bonus for each sea lion, adds to bank
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: bank has bonus revenue added
 *******************************************************/
void Zoo::eventBoom()
{
    //bonus accumulator
    int boomBonus = 0;

    //accumulate random bonus for each sea lion
    for(int i = 0; i < numSeaLions; i++)
    {
        boomBonus += ((rand() % 251) + 150);
    }

    //add to bank and report
    bank += boomBonus;
    cout << "During the attendance boom, your " << numSeaLions;
    cout << " sea lions generated an extra $" << boomBonus;
    cout << " worth of revenue!" << endl;
}

/*******************************************************
 * Function: void Zoo::addSeaLion(SeaLion newSeaLion)
 * Description: adds sea lion to sea lion array
 * Parameters: newSeaLion - sea lion to add
 * Pre-Conditions: none
 * Post-Conditions: sea lion array has newSeaLion added
 *******************************************************/
void Zoo::addSeaLion(SeaLion newSeaLion)
{   
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

    //increment sea lions
    numSeaLions++;
}

/*******************************************************
 * Function: void Zoo::removeSeaLion(int index)
 * Description: removes sea lion from array
 * Parameters: index - index of sea lion to remove
 * Pre-Conditions: sea lion at index exists
 * Post-Conditions: sea lion at index is removed
 *******************************************************/
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

    //delete old array and replace
    delete[] seaLions;
    seaLions = temp;
}

/*******************************************************
 * Function: void Zoo::addBlackBear(BlackBear newBlackBear)
 * Description: adds black bear to array
 * Parameters: newBlackBear - black bear to add to array
 * Pre-Conditions: none
 * Post-Conditions: newBlackBear is added to bear array
 *******************************************************/
void Zoo::addBlackBear(BlackBear newBlackBear)
{   
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

    //increment number of bears
    numBears++;
}

/*******************************************************
 * Function: void Zoo::removeBlackBear(int index)
 * Description: removes black bear at index from array
 * Parameters: index - index of black bear to remove
 * Pre-Conditions: black bear exists at index
 * Post-Conditions: black bear at index is removed
 *******************************************************/
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

    //delete old array and replace
    delete[] bears;
    bears = temp;
}

/*******************************************************
 * Function: void Zoo::addTiger(Tiger newTiger)
 * Description: adds new tiger to tiger array
 * Parameters: newTiger - tiger to add to array
 * Pre-Conditions: none
 * Post-Conditions: tiger newTiger is added to array
 *******************************************************/
void Zoo::addTiger(Tiger newTiger)
{   
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

    //increment number of tigers
    numTigers++;
}

/*******************************************************
 * Function: void Zoo::removeTiger(int index)
 * Description: removes tiger at index from array
 * Parameters: index - index of tiger to remove
 * Pre-Conditions: tiger exists at index
 * Post-Conditions: tiger at index is removed from array
 *******************************************************/
void Zoo::removeTiger(int index)
{
    //if there's only one animal
    if(numTigers == 1)
    {
        numTigers--; //reset count to 0
        delete[] tigers; //delete array entirely
        return; //exit function
    }

    //new array with one less element
    Tiger * temp = new Tiger[--numTigers];
    int writeIndex = 0;

    //copy over all members except one to remove
    for(int i = 0; i < numTigers; i++)
    {
        if(i != index) temp[writeIndex++] = tigers[i];
    }

    //delete old array and replace
    delete[] tigers;
    tigers = temp;
}

/*******************************************************
 * Function: bool Zoo::userContinue()
 * Description: determines if user wants to continue the game
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns player choice to continue game
 *******************************************************/
bool Zoo::userContinue()
{   
    //user input 
    int input;

    //repeat until valid input is entered
    do
    {
        cout << "Would you like to continue to the next month? (1 = yes, 0 = no): ";
        cin >> input;
    } while (input != 0 && input != 1);

    //return validated input 
    return input;
}