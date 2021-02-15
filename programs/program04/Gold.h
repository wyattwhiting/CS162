/******************************************************
** File: Gold.h
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Gold header file
******************************************************/

#ifndef GOLD_H
#define GOLD_H

#include "Event.h"

using namespace std;

class Gold : public Event
{
    private:
        //their own implementation
        void percept();
        void encounter();

    public:
        //constructor and destructor
        Gold();
        ~Gold();
};

#endif