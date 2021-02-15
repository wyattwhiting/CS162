/******************************************************
** File: Pit.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Pit implentation file
******************************************************/

#include "MasterInclude.h"

/*******************************************************
 * Function: Pit::Pit()
 * Description: pit constructor 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sets map icon to 'P'
 *******************************************************/
Pit::Pit() { this->mapIcon = 'P'; }

/*******************************************************
 * Function: Pit::~Pit()
 * Description: pit destructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: pit destroyed
 *******************************************************/
Pit::~Pit() {}

/*******************************************************
 * Function: void Pit::percept()
 * Description: prints percept message for pit
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Pit::percept() { cout << "You feel a frigid draft wafting from nearbly..." << endl; }

/*******************************************************
 * Function: void Pit::encounter()
 * Description: prints encounter message for pit
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Pit::encounter() { cout << "You step into the room and immediately freefall. " << endl; }