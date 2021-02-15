/******************************************************
** File: Bats.h
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Bats header file
******************************************************/

#ifndef BATS_H
#define BATS_H

#include "Event.h"

using namespace std;

class Bats : public Event
{
    private:
        //polymorhic functions
        void percept();
        void encounter();

    public:
        //constructor and destructor
        Bats();
        ~Bats();

};

#endif