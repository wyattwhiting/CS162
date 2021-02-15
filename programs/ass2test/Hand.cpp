/******************************************************
** Program file: Hand.cpp
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: Implementation file for Hand class
** Input: none at large
** Output: none at large
******************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Hand.h"

using namespace std;

/*******************************************************
 * Function: Hand::Hand()
 * Description: default hand constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: Hand is initialized with numCards = 0
 *                  and a single null-valued card
 *******************************************************/
Hand::Hand()
{
    //initialize blank hand. Has numCards = 0 and array of single null card
    numCards = 0;
    cards = new Card[1];
}

/*******************************************************
 * Function: Hand::Hand(const Hand & oldHand)
 * Description: Hand class copy constructor
 * Parameters: const Hand & oldHand : object to be copied
 * Pre-Conditions: none
 * Post-Conditions: oldHand is returned to the calling function
 *******************************************************/
Hand::Hand(const Hand & oldHand)
{
    //copy numCards
    numCards = oldHand.numCards; 

    //make new dynamic memory with given number of members
    cards = new Card[oldHand.numCards]; 

    //loop through all members in oldHand
    for(int i = 0; i < oldHand.numCards; i++) 
    {
        //copy member over
        cards[i] = oldHand.cards[i]; 
    }
}

/*******************************************************
 * Function: Hand & Hand::operator=(const Hand & oldHand) 
 * Description: operator= overload for Hand class
 * Parameters: const Hand & oldHand
 * Pre-Conditions: none
 * Post-Conditions: receiving object takes all values of oldHand
 *******************************************************/
Hand & Hand::operator=(const Hand & oldHand) 
{
    //copy number of cards
    numCards = oldHand.numCards; 

    //delete current array
    delete[] cards; 

    //make new array based on size of old
    cards = new Card[numCards]; 

    //go through new array
    for(int i = 0; i < numCards; i++) 
    {
        //copy the card over
        cards[i] = oldHand.cards[i]; 
    }

    //return pointer to self
    return *this; 
}

/*******************************************************
 * Function: Hand::~Hand()
 * Description: Hand destructor
 * Parameters: none
 * Pre-Conditions: Hand is no longer needed in program
 * Post-Conditions: memory for cards array is cleared,
 *                  and Hand is destroyed
 *******************************************************/
Hand::~Hand() { delete[] cards; }

/*******************************************************
 * Function: int Hand::getNumCards()
 * Description: returns number of cards in Hand
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int Hand::getNumCards() { return numCards; }

/*******************************************************
 * Function: Card Hand::getCard(int index)
 * Description: returns the card at index 'index' in Hand
 * Parameters: int index - index of the card to retreive
 * Pre-Conditions: card array has a card at index
 * Post-Conditions: none, hand state unchanged
 *******************************************************/
Card Hand::getCard(int index) { return cards[index]; }

/*******************************************************
 * Function: void Hand::printHand() 
 * Description: prints a list of the Hand
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: hand is printed to screen
 *******************************************************/
void Hand::printHand() 
{
    //for all cards in deck
    for(int i = 0; i < numCards; i++) 
    {
        //print index and card at that index
        cout << i << ": " << cards[i].toString() << endl; 
    }
}

/*******************************************************
 * Function: bool Hand::hasCardOr8(Card checkCard) 
 * Description: checks if the hand has a card that either
 *              matches the suit or rank of checkCard, or   
 *              the hand has an 8
 * Parameters: Card checkCard - Card to check against
 * Pre-Conditions: Hand has cards in it
 * Post-Conditions: none, state of Hand unchanged
 *******************************************************/
bool Hand::hasCardOr8(Card checkCard) 
{
    //loop through all cards in hand
    for(int i = 0; i < numCards; i++) 
    {
        //if card is an 8
        if(cards[i].getRank() == 8) 
        {
            return true;
        }

        //if ranks are equal
        if(cards[i].getRank() == checkCard.getRank()) 
        {
            return true; 
        }

        //if suits are equal
        if(cards[i].getSuit() == checkCard.getSuit())
        {
            return true; 
        } 
    }

    //otherwise, return false
    return false; 
}

/*******************************************************
 * Function: bool Hand::cardAtIndexCanCover(int i, Card pileCard)
 * Description: indicates if card at a given index can cover
 *              the pileCard
 * Parameters: int i - index to check
 *             Card pileCard - use to determine rank or suit match
 * Pre-Conditions: Hand has cards in the array
 * Post-Conditions: none, Hand state unchanged
 *******************************************************/
bool Hand::cardAtIndexCanCover(int i, Card pileCard)
{
    //if cards[i] matches any of the criteria
    if(cards[i].getRank() == pileCard.getRank() || cards[i].getSuit() == pileCard.getSuit() || cards[i].getRank() == 8)
    {
        return true;
    }

    //otherwise, return false
    return false; 
}

/*******************************************************
 * Function: int Hand::findMatchIndex(Card pileCard)
 * Description: finds the index in the card array of
 *              the first card which can cover pileCard
 * Parameters: Card pileCard - the card for which we want
 *                             to find the cover
 * Pre-Conditions: the card array must have a card which 
 *                 we know to match. Use other functions
 *                 to verify before calling.
 * Post-Conditions: none, Hand state remains unchanged
 *******************************************************/
int Hand::findMatchIndex(Card pileCard)
{
    //for all cards in deck
    for(int i = 0; i < numCards; i++) 
    {
        //return index if potential match is found there
        if(cardAtIndexCanCover(i, pileCard)) return i; 
    }

    //if it gets here, something went wrong
    cout << "ERROR THERE IS NO MATCHING CARD" << endl;
    return -1;
}

/*******************************************************
 * Function: void Hand::addToCards(Card newCard)
 * Description: adds newCard to the hand
 * Parameters: Card newCard - the card to add to the deck
 * Pre-Conditions: none
 * Post-Conditions: card array has all previous cards with
 *                  newCard appended to the end
 *******************************************************/
void Hand::addToCards(Card newCard)
{
    //catch for null deck
    if(cards[0].getRank() == 0 || cards[0].getSuit() == 0) 
    {   
        //just overwrite the existing one
        cards[0] = newCard; 
        numCards = 1; 
    }

    //otherwise
    else
    {   

        //make temp array
        Card * temp = new Card[numCards + 1];

        //loop through cards in current array
        for(int i = 0; i < numCards; i++)
        {
            //copy to temp array
            temp[i] = cards[i]; 
        }

        //destroy old array, copy over new one
        delete[] cards; 
        cards = temp; 

        //assign new card to end of array, increment numCards
        cards[numCards++] = newCard; 
    }
}

/*******************************************************
 * Function: Card Hand::drawCardFromIndex(int index)
 * Description: draws the card from te given index and returns 
 *              it to the point it was called.
 * Parameters: int index - index of the card to take
 * Pre-Conditions: index parameter must be valid array index
 * Post-Conditions: card array has card at index removed. all
 *                  cards after are shifted downwards in their
 *                  respective indices. 
 *******************************************************/
Card Hand::drawCardFromIndex(int index)
{
    //make copy of card at index
    Card retCard = cards[index]; 

    //new array with one less card
    Card * tempCards = new Card[numCards - 1]; 

    //index for new array to write to
    int writeIndex = 0; 

    //loop through cards in hand
    for(int i = 0; i < numCards; i++) 
    {
        //as long as we're not on the returning card
        if(i != index) 
        {
            //copy to new card array, increment writing index
            tempCards[writeIndex++] = cards[i]; 
        }
    }

    //decrement numCards
    numCards -= 1; 
    delete[] cards; 
    cards = tempCards;

    //return the card
    return retCard; 
}