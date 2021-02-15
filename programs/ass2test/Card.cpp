/******************************************************
** Program file: Card.cpp
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: Implementation file for Card class
** Input: none at large
** Output: none at large
******************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Card.h"

using namespace std;

/*******************************************************
 * Function: Card::Card()
 * Description: default card constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Note: should never be in this state
 *******************************************************/
Card::Card()
{
    //cout << "Default Card constructor called..." << endl;
    rank = 0;
    suit = 0;
}

/*******************************************************
 * Function: Card::Card(int newRank, int newSuit)
 * Description: overloaded card constructor
 * Parameters: int newRank - rank for the card
 *             int newSuit = suit for the card
 * Pre-Conditions: none
 * Post-Conditions: card has specified rank and suit
 *******************************************************/
Card::Card(int newRank, int newSuit)
{
    //cout << "Overloaded Card constructor called..." << endl;
    rank = newRank;
    suit = newSuit;
}

/*******************************************************
 * Function: Card & Card::operator=(const Card & oldCard)
 * Description: operator= overloaded for Card class
 * Parameters: const Card & oldCard
 * Pre-Conditions: none
 * Post-Conditions: object assumes attributes of oldCard
 *******************************************************/
Card & Card::operator=(const Card & oldCard)
{
    //cout << "Card '=' operator called..." << endl;
    rank = oldCard.rank;
    suit = oldCard.suit;
    return *this;
}

/*******************************************************
 * Function: Card::Card(const Card & oldCard) 
 * Description: copy constructor
 * Parameters: const Card & oldCard
 * Pre-Conditions: none
 * Post-Conditions: Card assumes attributes of oldCard
 *******************************************************/
Card::Card(const Card & oldCard) 
{   
    //copy variables over
    rank = oldCard.rank;
    suit = oldCard.suit;
}

/*******************************************************
 * Function: Card::~Card()
 * Description: card destructor
 * Parameters: none
 * Pre-Conditions: Card object exists
 * Post-Conditions: Card object no longer exists
 *******************************************************/
Card::~Card() {}

/*******************************************************
 * Function: int Card::getRank()
 * Description: returns the rank of the card
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none, card state unchanged
 *******************************************************/
int Card::getRank() { return rank; }

/*******************************************************
 * Function: int Card::getSuit()
 * Description: returns the suit of the card
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none, card state unchanged
 *******************************************************/
int Card::getSuit() { return suit; }

/*******************************************************
 * Function: string Card::toString()
 * Description: returns a string representation of the card
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none, card state remains unchanged
 *******************************************************/
string Card::toString()
{   
    //arrays for translating numbers to cards
    //order really doesn't matter
    string suitArr[] = {"diamond", "heart", "club", "spade"};
    string rankArr[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    return "|" + rankArr[rank - 1] + " " + suitArr[suit - 1] + "| "; //return string representation of card
}

/*******************************************************
 * Function: void Card::setRank(int newRank)
 * Description: sets the rank of the card
 * Parameters: int newRank - new rank for the card
 * Pre-Conditions: none
 * Post-Conditions: card assumes rank newRank
 * Note: should never be used
 *******************************************************/
void Card::setRank(int newRank) { rank = newRank; }

/*******************************************************
 * Function: void Card::setSuit(int newSuit)
 * Description: sets the suit of the card
 * Parameters: int newSuit - new suit for the card
 * Pre-Conditions: none
 * Post-Conditions: Card assumes suit newSuit
 * note: should never be used
 *******************************************************/
void Card::setSuit(int newSuit) { suit = newSuit; }