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
};

#endif