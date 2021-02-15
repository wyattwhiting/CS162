/******************************************************
** File: Bats.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Bats implementation file
******************************************************/

#include "MasterInclude.h"

/*******************************************************
 * Function: Bats::Bats()
 * Description: bat constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sets map icon to 'B'
 *******************************************************/
Bats::Bats() { this->mapIcon = 'B'; }

/*******************************************************
 * Function: Bats::~Bats()
 * Description: bat destructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: bat destroyed
 *******************************************************/
Bats::~Bats() {}

/*******************************************************
 * Function: void Bats::percept()
 * Description: prints bat percept message
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Bats::percept() { cout << "You hear the sound of wings fluttering..." << endl; }

/*******************************************************
 * Function: void Bats::encounter()
 * Description: prints encounter message for bats
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Bats::encounter() { cout << "You get swarmed by bats and get carried to a new room." << endl; }