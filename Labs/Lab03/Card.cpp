#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"

using namespace std;

Card::Card() {
    suit = "unk";
    rank = 0;
}

Card::Card(string s, int r) {
    setSuit(s);
    setRank(r);
}

void Card::setSuit(string s) { suit = s; }

void Card::setRank(int r) { rank = r; }

string Card::getSuit() { return suit; }

int Card::getRank() { return rank; }
