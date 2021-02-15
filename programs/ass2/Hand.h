#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Card.h"

using namespace std;

class Hand {
    private:
        Card* cards;   // Heap array of cards
        int numCards;  // Number of cards in the hand.
    public:
        //constructor
        Hand();
        Hand(const Hand &);
        Hand & operator=(const Hand &);

        //destructor
        ~Hand();

        //getters
        int getNumCards();
        Card getCard(int);
        void printHand();
        bool hasValidMatch(Card);

        //setters
        void addToCards(Card);
        Card drawCardAtIndex(int);
  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif