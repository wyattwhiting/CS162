#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

using namespace std;

Deck::Deck() //default constructor
{
    numCards = 52;
    int index = 0;
    //cout << "Deck constructor called..." << endl;
    for(int i = 0; i < 13; i++) //ranks
    {
        for(int j = 0; j < 4; j++) //suits
        {
            cards[index++] = Card(i + 1, j + 1);
        }
    }
}

Deck::Deck(const Deck & oldDeck) 
{
    numCards = oldDeck.numCards;
    for(int i = 0; i < 52; i++) 
    {
        cards[i] = oldDeck.cards[i];
    }

}

Deck & Deck::operator=(const Deck & oldDeck)
{
    if(this != &oldDeck) //as long as it's a different deck
    {
        for(int i = 0; i < 52; i++)
        {
            cards[i] = oldDeck.cards[i];
        }
    }
    return *this;
}

Deck::~Deck()
{
    //cout << "Deck destructor called..." << endl;
}

int Deck::getNumCards() { return numCards; }


Card Deck::drawTopCard() {
    if(numCards == 0) return Card(); //return null card in case we try to draw one when none exist
    //otherwise
    
    return cards[--numCards]; //return top index
}

Card Deck::getTopCard() { return cards[numCards - 1]; }

void Deck::printDeck()
{
    for(int i = 0; i < numCards; i++)
    {
        cout << "index: " << i << cards[i].toString() << endl;
    }
}

void Deck::shuffle()
{
    //cout << "Overload deck shuffle called..." << endl;
    srand(time(NULL));
    Card swapCard;
    int index1 = 0;
    int index2 = 0;
    for(int i = 0; i < 10000; i++)
    {
        //two random indices
        index1 = rand() % numCards;
        index2 = rand() % numCards;

        //make copy of 1, 1 gets 2, 2 gets copy
        swapCard = cards[index1];
        cards[index1] = cards[index2];
        cards[index2] = swapCard;
    }
}