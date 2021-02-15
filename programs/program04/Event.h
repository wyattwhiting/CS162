/******************************************************
** File: Event.h
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Event header file
******************************************************/

#ifndef EVENT_H
#define EVENT_H

using namespace std;

class Event
{
    protected:
        char mapIcon;
    private:
        
    public:
        //pure virtual functions for polymorphism
        virtual void percept() = 0;
        virtual void encounter() = 0; 

        //constructor and destructor
        Event();
        ~Event();

        char getChar();

};

#endif