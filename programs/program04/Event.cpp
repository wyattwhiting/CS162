/******************************************************
** File: Event.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Event implementation file
******************************************************/

#include "MasterInclude.h"

/*******************************************************
 * Function: Event::Event()
 * Description: event constructor   
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: event is given default map icon of ' '
 *******************************************************/
Event::Event() { this->mapIcon = ' '; }

/*******************************************************
 * Function: Event::~Event()
 * Description: event destructor
 * Parameters: none
 * Pre-Conditions: event exists
 * Post-Conditions: event no longer exists
 *******************************************************/
Event::~Event() {}

/*******************************************************
 * Function: char Event::getChar()
 * Description: returns Event map icon
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns map icon, event is unchanged
 *******************************************************/
char Event::getChar() { return this->mapIcon; }
