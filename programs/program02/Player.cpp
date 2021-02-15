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

Hand Player::getHand() { return hand; }
string Player::getName() { return name; }
int Player::getPlayerType() { return playerType; }

void Player::addToHand(Card newCard)
{    
    hand.addToCards(newCard);
}

void Player::printHand() { hand.printHand(); }

bool Player::hasValidCard(Card checkCard)
{
    return hand.hasValidMatch(checkCard);
}

Card Player::humanGetCardChoice(Card topCard)
{   
    //must return card with either same rank, same suit, or an 8
    int input; //input variable
    bool inRange = false;
    bool canBePlayed = false;

    //while 
    //} while(!flag8 && (hand.getCard(input).getRank() != topCard.getRank() && hand.getCard(input).getSuit() != topCard.getSuit())); 
    do
    {
        do
        {
            cout << "Please enter the index of the card to play: ";
            cin >> input;
            if(input >= 0 && input <= hand.getNumCards() - 1) inRange = true;

            //if in range, short circuit skips second half
        } while (!inRange);

        cout << "choice in valid range" << endl;
        //check if card either 
        if(hand.getCard(input).getRank() == 8) canBePlayed = true;
        if(hand.getCard(input).getRank() == topCard.getRank() || hand.getCard(input).getSuit() == topCard.getSuit()) canBePlayed = true;
    } while(!canBePlayed);
    

    cout << "returning card at index: " << input << endl;
    return hand.drawCardAtIndex(input);
}