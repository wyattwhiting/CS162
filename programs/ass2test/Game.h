/******************************************************
** Program file: Game.h
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: header file for Game class
** Input: none
** Output: none
******************************************************/

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
        Deck stock;
        Player players[2];
        Card pileCard;
    public:
        //constructors
        Game();

        //destructors
        ~Game();

        //getters
        Deck getCards();
        Player getPlayer(int);
        Card getPileCard();
        bool gameShouldLoop();

        //misc
        void playGame();
        void humanTurn();
        void humanTurnHelper();
        void playerTurnIntro();
        Card playerFix8();
        void computerTurn();
        void computerTurnHelper();
        void computerTurnIntro();
        Card computerFix8();
        void showWinner();

  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif