/******************************************************
** File: Wumpus.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Wumpus implementation file
******************************************************/

#include "MasterInclude.h"

/*******************************************************
 * Function: Wumpus::Wumpus()
 * Description: wumpus constructor 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sets map icon to 'W'
 *******************************************************/
Wumpus::Wumpus() { this->mapIcon = 'W'; }

/*******************************************************
 * Function: Wumpus::~Wumpus()
 * Description: wupus destructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: wumpus destroyed
 *******************************************************/
Wumpus::~Wumpus() {}

/*******************************************************
 * Function: void Wumpus::percept()
 * Description: prints perfcept message for wumpus
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Wumpus::percept() { cout << "You nose detects an offensive odor..." << endl; }

/*******************************************************
 * Function: void Wumpus::encounter()
 * Description: prints encounter message for wumpus
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Wumpus::encounter() { cout << "The wumpus wakes up and devours you whole. " << endl; }
