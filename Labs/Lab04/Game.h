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

};

#endif