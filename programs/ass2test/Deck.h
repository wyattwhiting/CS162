/******************************************************
** Program file: Deck.h
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: header file for Deck class
** Input: none  
** Output: none
******************************************************/

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Card.h"

using namespace std;

class Deck 
{
    private:
        Card cards[52];
        int numCards;  // Number of cards remaining in the deck.
    public:
        //constructors
        Deck();
        Deck(const Deck &);
        Deck & operator=(const Deck &);

        //destructor
        ~Deck();

        //getters
        int getNumCards();
        Card drawTopCard();

        //useful functions
        void printDeck();
        void shuffle();
    // must have constructors, destructor, accessor methods, and mutator methods

};

#endif