#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Player.h"

using namespace std;

Player::Player()
{
    hand = Hand();
    name = "unk";
    playerType = -1;
    //cout << "Default Player constructor called..." << endl;
    
}

Player::Player(int n)
{
    hand = Hand();
    playerType = n;
    if(playerType == 0) //human
    {
        cout << "Enter your name: ";
        cin >> name;
    } 
    else //playerType != 0 implies robot
    {
        cout << "Creating computer player..." << endl;
        name = "HAL";
    }
}

Player::Player(const Player & newPlayer)
{
    //cout << "Player copy constructor called..." << endl;
    hand = newPlayer.hand;
    name = newPlayer.name;
}

Player & Player::operator=(const Player & oldPlayer)
{
    //cout << "about to overwrite hand..." << endl;
    hand = oldPlayer.hand;

    //cout << "hand overwritten..." << endl;
    name = oldPlayer.name;
    //cout << "name overwritten" << endl;
    return *this;
}

Player::~Player()
{
    //cout << "Player destructor called..." << endl;
}
