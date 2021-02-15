#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Card.h"

using namespace std;

Card::Card()
{
    //cout << "Default Card constructor called..." << endl;
    rank = 0;
    suit = 0;
}

Card::Card(int newRank, int newSuit)
{
    //cout << "Overloaded Card constructor called..." << endl;
    rank = newRank;
    suit = newSuit;
}

Card & Card::operator=(const Card & oldCard)
{
    //cout << "Card '=' operator called..." << endl;
    rank = oldCard.rank;
    suit = oldCard.suit;
    return *this;
}

Card::Card(const Card & oldCard) 
{
    rank = oldCard.rank;
    suit = oldCard.suit;
}

Card::~Card()
{
    //cout << "Card destructor called..." << endl;

}

//getters
int Card::getRank() { return rank; }
int Card::getSuit() { return suit; }
string Card::toString()
{   
    //arrays for translating numbers to cards
    //order really doesn't matter
    string suitArr[] = {"diamond", "heart", "club", "spade"};
    string rankArr[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    return "|" + rankArr[rank - 1] + " " + suitArr[suit - 1] + "|";
}

void Card::setRank(int newRank) { rank = newRank; }
void Card::setSuit(int newSuit) { suit = newSuit; }