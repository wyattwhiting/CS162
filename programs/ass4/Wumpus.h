/******************************************************
** File: Wumpus.h
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Wumpus header file
******************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"

using namespace std;

class Wumpus : public Event
{
    private:
        //polymorphic function implementation
        void percept();
        void encounter();

    public:
        //constructor and destructor
        Wumpus();
        ~Wumpus();

};

#endif