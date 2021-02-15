#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"

Deck::Deck() {
    cout << "Making new deck..." << endl;
    cards = new Card[52];
    for(int i = 0; i < 13; i++) {
        cards[i] = Card("diamond", i + 1);
    }
    for(int i = 0; i < 13; i++) {
        cards[13 + i] = Card("club", i + 1);
    }
    for(int i = 0; i < 13; i++) {
        cards[26 + i] = Card("heart", i + 1);
    }
    for(int i = 0; i < 13; i++) {
        cards[39 + i] = Card("spade", i + 1);
    }
}

Deck::~Deck() {
    cout << "Deleting deck..." << endl;
    delete[] cards;
}

Deck * Deck::getDeck() {
    cout << "Getting deck..." << endl;
    return NULL;
}

void Deck::shuffleDeck() {
    cout << "Shuffling deck..." << endl;
    string s;
    int a;
    int card1;
    int card2;
    srand(time(NULL));

    for(int i = 0; i < 4000; i++) {
        card1 = rand() % 52;
        card2 = rand() % 52;

        s = cards[card1].getSuit();
        a = cards[card1].getRank();

        cards[card1].setSuit(cards[card2].getSuit());
        cards[card1].setRank(cards[card2].getRank());

        cards[card2].setSuit(s);
        cards[card2].setRank(a);
    }
    cout << "Deck shuffled" << endl;
}

void Deck::printDeck() {
    for(int i = 0; i < 52; i++) {
        cout << "Card " << i << ":" << cards[i].getRank() << " " << cards[i].getSuit() << endl;
    }
}