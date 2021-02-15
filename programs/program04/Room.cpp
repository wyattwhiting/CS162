/******************************************************
** File: Room.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Room implementation file
******************************************************/

#include "MasterInclude.h"

/*******************************************************
 * Function: Room::Room()
 * Description: room constructor
 * Parameters: none
 * Pre-Conditions: room does not exist
 * Post-Conditions: room exists with null room event
 *******************************************************/
Room::Room()
{
    //rooms start with no event
    roomEvent = nullptr; 
}

/*******************************************************
 * Function: Room::~Room()
 * Description: room destructor
 * Parameters: none
 * Pre-Conditions: room exists
 * Post-Conditions: room event is deleted and room no longer exists
 *******************************************************/
Room::~Room() { if(roomEvent != nullptr) delete roomEvent; }

/*******************************************************
 * Function: void Room::roomPercept()
 * Description: calls the room event percept if it exists
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
void Room::roomPercept()
{
    //if room is empty, do nothing
    if(roomEvent == nullptr) return;

    //otherwise, call percept method for room event
    this->roomEvent->percept();
}

/*******************************************************
 * Function: bool Room::isEmpty()
 * Description: checks if room has a non-null event
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns if room is empty, gamestate unchanged
 *******************************************************/
bool Room::isEmpty() { return roomEvent == nullptr; }

/*******************************************************
 * Function: void Room::checkWumpus(bool & wumpusHit)
 * Description: checks if wumpus is hit and updates hit flag
 *              removes wumpus from room if hit
 * Parameters: bool & wumpusHit
 * Pre-Conditions: room must be instantiated
 * Post-Conditions: wumpus is removed if hit and flag is updated as appropriate
 *******************************************************/
void Room::checkWumpus(bool & wumpusHit)
{
    //if room is populated and is a wumpus
    if(roomEvent != nullptr && this->getEventChar() == 'W') 
    {   
        //print message and update the flag
        cout << "You hear the Wumpus cry out in pain." << endl;
        wumpusHit = true;

        //kill the wumpus
        delete roomEvent;

        //reset event pointer
        roomEvent = nullptr;
    }
}

/*******************************************************
 * Function: void Room::setEvent(Event * newEvent)
 * Description: sets the room event pointer
 * Parameters: Event * newEvent - pointer for new event 
 * Pre-Conditions: room is instantiated
 * Post-Conditions: event pointer is updated to argument
 *******************************************************/
void Room::setEvent(Event * newEvent) { 
    if(roomEvent != nullptr) delete roomEvent;
    roomEvent = newEvent; 
}

/*******************************************************
 * Function: void Room::deleteEvent()
 * Description: deletes event from room
 * Parameters: none
 * Pre-Conditions: room is instantiated
 * Post-Conditions: event at pointer is deleted and pointer is set to nullptr
 *******************************************************/
void Room::deleteEvent()
{
    //if room is populated 
    if(roomEvent != nullptr)
    {
        //delete the event and reset pointer
        delete roomEvent;
        roomEvent = nullptr;
    }
}

/*******************************************************
 * Function: void Room::interact()
 * Description: allows player to interact with room event
 * Parameters: none
 * Pre-Conditions: room is instantiated
 * Post-Conditions: deletes room event if it is gold
 *******************************************************/
void Room::interact()
{
    //do nothing if nothing is here
    if(roomEvent == nullptr) return; 

    //encounter the room event
    roomEvent->encounter();

    //remove the gold if that's the case
    if(roomEvent->getChar() == 'G') deleteEvent();
}

/*******************************************************
 * Function: char Room::getEventChar()
 * Description: gets the character representing the map icon for room event
 * Parameters: none
 * Pre-Conditions: room is instantiated
 * Post-Conditions: returns appropriate character for specific room event
 *******************************************************/
char Room::getEventChar()
{
    //if room is empty, return a space
    if(roomEvent == nullptr) return ' ';

    //otherwise return the unique event charcter
    else return roomEvent->getChar();
}