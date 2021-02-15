/******************************************************
** File: Pit.h
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Pit header file
******************************************************/

#ifndef PIT_H
#define PIT_H

#include "Event.h"

using namespace std;

class Pit : public Event
{
    private:
        //polymorphic function implementation
        void percept();
        void encounter();

    public:
        //constructor and destructor
        Pit();
        ~Pit();

};

#endif