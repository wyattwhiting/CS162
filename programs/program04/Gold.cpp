/******************************************************
** File: Gold.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Gold implementation file
******************************************************/

#include "MasterInclude.h"

/*******************************************************
 * Function: Gold::Gold()
 * Description: gold constructor    
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: gold event exists with map icon 'G'
 *******************************************************/
Gold::Gold() { this->mapIcon = 'G'; }

/*******************************************************
 * Function: Gold::~Gold()
 * Description: gold destructor 
 * Parameters: none
 * Pre-Conditions: gold event exists
 * Post-Conditions: gold event no longer exists
 *******************************************************/
Gold::~Gold() {}

/*******************************************************
 * Function: void Gold::percept()
 * Description: prints message for gold perception
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Gold::percept() { cout << "Something shiny catches your eye..." << endl; }

/*******************************************************
 * Function: void Gold::encounter()
 * Description: prints message for player when gold is encountered
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Gold::encounter() { cout << "You stumble upon a room fit for a pharaoh. You pick up what you can." << endl; }