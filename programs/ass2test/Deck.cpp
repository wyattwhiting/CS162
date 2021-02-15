/******************************************************
** Program file: Deck.cpp
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: Implementation file for Deck class
** Input: none at large
** Output: none at large
******************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

using namespace std;

/*******************************************************
 * Function: Deck::Deck()
 * Description: Deck constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: Deck is initialized with standard 52 cards
 *******************************************************/
Deck::Deck() 
{
    //initilize some variables
    numCards = 52;
    int index = 0;


    //for all ranks
    for(int i = 0; i < 13; i++)
    {
        //for all suits
        for(int j = 0; j < 4; j++)
        {
            //add card with rank and suit to deck
            cards[index++] = Card(i + 1, j + 1);
        }
    }
}

/*******************************************************
 * Function: Deck::Deck(const Deck & oldDeck) 
 * Description: copy constructor for Decks
 * Parameters: const Deck & oldDeck
 * Pre-Conditions: oldDeck must be initiaited object
 * Post-Conditions: calling object assumes identity of oldDeck
 *******************************************************/
Deck::Deck(const Deck & oldDeck) 
{
    //copy over number of cards
    numCards = oldDeck.numCards;

    //copy over the cards
    for(int i = 0; i < 52; i++) 
    {
        cards[i] = oldDeck.cards[i];
    }

}

/*******************************************************
 * Function: Deck & Deck::operator=(const Deck & oldDeck)
 * Description: Deck operator= overload
 * Parameters: const Deck & oldDeck
 * Pre-Conditions: oldDeck is inititalized Deck object
 * Post-Conditions: new deck assumes all aspects of old deck
 *******************************************************/
Deck & Deck::operator=(const Deck & oldDeck)
{
    //as long as it's a different deck
    if(this != &oldDeck) 
    {
        //loop through cards
        for(int i = 0; i < 52; i++) 
        {
            //copy them over
            cards[i] = oldDeck.cards[i]; 
        }
    }

    //return pointer to self
    return *this; 
}

/*******************************************************
 * Function: Deck::~Deck()
 * Description: deck destructor
 * Parameters: none
 * Pre-Conditions: deck exists
 * Post-Conditions: deck no longer exists
 *******************************************************/
Deck::~Deck() {}

/*******************************************************
 * Function: int Deck::getNumCards()
 * Description: returns the number of cards in the deck
 * Parameters: none
 * Pre-Conditions: Deck is initialized
 * Post-Conditions: none, Deck state is unchanged
 *******************************************************/
int Deck::getNumCards() { return numCards; }

/*******************************************************
 * Function: Card Deck::drawTopCard()
 * Description: draws top card from deck and adjusts numCards
 *              indicator
 * Parameters: none
 * Pre-Conditions: Deck has at least one card remaining
 * Post-Conditions: top card no longer accessible. 
 *******************************************************/
Card Deck::drawTopCard() 
{
    //return null card in case we try to draw one when none exist
    if(numCards == 0) return Card(); 

    //return top index
    return cards[--numCards]; 
}

/*******************************************************
 * Function: void Deck::printDeck()
 * Description: prints the current state of the deck
 * Parameters: none 
 * Pre-Conditions: Deck is initialized and has at least one card
 * Post-Conditions: none, Deck state is unchanged
 *******************************************************/
void Deck::printDeck()
{
    //loop through cards in deck
    for(int i = 0; i < numCards; i++) 
    {
        //print out string representation of each in turn
        cout << "index: " << i << cards[i].toString() << endl; 
    }
}

/*******************************************************
 * Function: void Deck::shuffle()
 * Description: shuffles the deck
 * Parameters: none
 * Pre-Conditions: deck has some order
 * Post-Conditions: deck no longer has that order
 *******************************************************/
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