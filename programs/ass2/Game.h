#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Deck.h"
#include "Player.h"

using namespace std;

class Game {
    private:
        Deck cards;
        Player players[2];
    public:
        //constructors
        Game();

        //destructors
        ~Game();

        //getters
        Deck getCards();
        Player getPlayer(int);

        //state checkers
        bool playerHasValidCard(int, Card);

        //misc
        void startGame();
        Card flipTopCard();
        void printHumanHand();
        void printComputerHand();
        Card getHumanCard(Card);
        void playerDrawCard(int);
        

  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif