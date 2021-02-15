#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

Game::Game()
{
    //cout << "Game constructor called..." << endl;

    //populate deck with 52 cards
    cards = Deck();

    //create human player
    players[0] = Player(0);

    //create computer player
    players[1] = Player(1);

    //shuffle the deck
    cards.shuffle();

    //deal 7 cards to each player
    for(int i = 0; i < 7; i++) 
    {
        players[0].addToHand(cards.drawTopCard());
        players[1].addToHand(cards.drawTopCard());
    }
    cout << "constructor finished" << endl;
}


Game::~Game() 
{
    //cout << "Game destructor called..." << endl;
}

Deck Game::getCards() { return cards; }
Player Game::getPlayer(int index) { return players[index]; }

bool Game::playerHasValidCard(int playerIndex, Card checkCard) 
{
    return players[playerIndex].hasValidCard(checkCard);
}

void Game::startGame()
{
    //print starting game banner
    cout << "---=== Starting Game ===---" << endl;

    //print pile card by drawing the top card


    //cout << "Pile card: | " + cards.drawTopCard().toString() + " |" << endl;
}

Card Game::flipTopCard()
{
    return cards.drawTopCard();
}

void Game::printHumanHand()
{
    cout << "---===<: Your Hand :>===---" << endl;
    players[0].printHand();
}

void Game::printComputerHand()
{
    cout << "---===<: Computer's Hand :>===---" << endl;
    players[1].printHand();
}

Card Game::getHumanCard(Card topCard)
{
    return players[0].humanGetCardChoice(topCard);
}

void Game::playerDrawCard(int playerIndex)
{
    players[playerIndex].addToHand(cards.drawTopCard());
    cout << "HERE" << endl;
}