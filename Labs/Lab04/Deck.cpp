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
