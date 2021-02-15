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

int Hand::getNumCards() { return numCards; }
Card Hand::getCard(int index) { return cards[index]; }

void Hand::printHand() 
{
    for(int i = 0; i < numCards; i++)
    {
        cout << "Card #" << i << " " << cards[i].toString() << endl;
    }
}

bool Hand::hasValidMatch(Card checkCard) 
{
    for(int i = 0; i < numCards; i++) //loop through all cards in hand
    {
        //check if either suits or ranks match
        if(cards[i].getRank() == 8) 
        {
            cout << "Hand has an 8" << endl;
            return true; //8s are good to use whenever
        }
        if(cards[i].getSuit() == checkCard.getSuit() || cards[i].getRank() == cards[i].getRank()) 
        {
            cout << "Card " << checkCard.toString() << " found in deck at index " << i << endl;
            return true; //return true if match is found
        }
    }
    return false; //otherwise, return false
}

void Hand::addToCards(Card newCard)
{
    if(cards[0].getRank() == 0 || cards[0].getSuit() == 0) //catch for null deck
    {   
        //cout << "void Hand::addToCards(Card newCard) " << newCard.getRank() << " " << newCard.getSuit() << endl;
        //cout << "NO CARDS... adding first" << endl;
        cards[0] = newCard; //just overwrite the existing one
        //DON'T increment, since it's at 1 already
    }
    else
    {   

        //make temp array
        Card * temp = new Card[numCards + 1];
        //cout << "Temp array made" << endl;

        //loop through cards in current array
        for(int i = 0; i < numCards; i++)
        {
            temp[i] = cards[i]; //copy to temp array
        }

        delete[] cards; //destroy old array
        cards = temp; //copy new one
        cards[numCards++] = newCard; //assign new card to end of array, increment numCards
    }
}

Card Hand::drawCardAtIndex(int index)
{
    Card * temp = new Card[numCards - 1]; //new card array with one less card
    Card returnCard = cards[index]; //card to return at current hand index

    int writeIndex = 0;
    for(int i = 0; i < numCards; i++) //loop through existant card array
    {
        if(i != index) temp[writeIndex++] = cards[i];
    }

    delete[] cards; //delete old deck
    cards = temp; //reassing pointer
    numCards--; //decrement number of cards to reflect new 

    cout << "Hand::drawCardAtIndex returning card at index: " << index << endl;
    return returnCard;
}