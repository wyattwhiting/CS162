#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Hand.h"

using namespace std;

Hand::Hand()
{
    //NOTE: There should NEVER be a hand with zero cards. That should be an impossible state
    //Zero is checked by the current card being a null card

    //default is 1 null card
    numCards = 1;
    cards = new Card[1];
    //cards[0] = Card(1, 1);
}


Hand::Hand(const Hand & oldHand) //hand copy constructor
{
    //cout << "Calling Hand copy constructor..." << endl;
    //delete[] cards;
    numCards = oldHand.numCards;
    cards = new Card[oldHand.numCards];
    for(int i = 0; i < oldHand.numCards; i++)
    {
        cards[i] = oldHand.cards[i];
    }
}

Hand & Hand::operator=(const Hand & oldHand) 
{
    numCards = oldHand.numCards;
    delete[] cards;

    cards = new Card[numCards];
    for(int i = 0; i < numCards; i++)
    {
        ///cout << i << i << i << endl;
        cards[i] = oldHand.cards[i];
    }
    return *this;
}

Hand::~Hand()
{
    //cout << "Hand destructor called..." << endl;
    delete[] cards;

}
