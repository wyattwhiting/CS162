#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Deck.h"

using namespace std;

int main() {
    Deck myDeck = Deck();

    myDeck.printDeck();
    myDeck.shuffleDeck();
    myDeck.printDeck();
    


    return 0;
}