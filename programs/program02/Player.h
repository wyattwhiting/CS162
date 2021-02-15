#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Hand.h"

using namespace std;

class Player {
    private:
        Hand hand;
        string name;
        int playerType;

    public:
        //constructors
        Player();
        Player(int);
        Player(const Player &);
        Player & operator=(const Player &);

        //destructor
        ~Player();

        //getters
        Hand getHand();
        string getName();
        int getPlayerType();

        //setters
        void addToHand(Card);

        //misc useful functions
        void printHand();
        bool hasValidCard(Card);
        Card humanGetCardChoice(Card);
        
    // must have constructors, destructor, accessor methods, and mutator methods

};

#endif