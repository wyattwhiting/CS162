/******************************************************
** File: Room.h
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Room header file
******************************************************/

#ifndef ROOM_H
#define ROOM_H

#include "Event.h"

using namespace std;

class Room
{
    private:
        Event * roomEvent;

    public:

        //constructor / destructor
        Room();
        ~Room();

        //functions
        void roomPercept();
        bool isEmpty();
        void checkWumpus(bool &);
        void setEvent(Event *);
        void deleteEvent();
        void interact();
        char getEventChar();

};

#endif