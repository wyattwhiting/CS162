#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Card.h"

using namespace std;

class Deck {
    private:
        Card * cards;

    public:
        //constructor and destructor
        Deck();
        ~Deck();

        //getters
        Deck * getDeck();

        //misc functions
        void shuffleDeck();
        void printDeck();

};


#endif