#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

Game::Game()
{
    cout << "Game constructor called..." << endl;

    //populate deck with 52 cards
    cards = Deck();

    //create human player
    players[0] = Player(0);

    //create computer player
    players[1] = Player(1);
}


Game::~Game() 
{
    cout << "Game destructor called..." << endl;
}

