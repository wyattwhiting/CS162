/******************************************************
** Program file: Player.cpp
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: Implementation file for Player class
** Input: none at large
** Output: none at large
******************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Player.h"

using namespace std;

/*******************************************************
 * Function: Player::Player()
 * Description: default player Constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: Player is in unique 'null' state
 * Note: There should never be a player of this type in 
 *       the game
 *******************************************************/
Player::Player()
{
    //start everything with unique values. I should never have these characters in the game proper
    hand = Hand();
    name = "unk ";
    playerType = -1;
}

/*******************************************************
 * Function: Player::Player(int n)
 * Description: overloaded Player class constructor
 * Parameters: int n - specifies player type, where
 *                     0 = human       1 = computer
 * Pre-Conditions: none
 * Post-Conditions: player is made of type according to
 *                  input. Instantiates names and makes
 *                  hands
 *******************************************************/
Player::Player(int n)
{   
    //initialize some stuff
    hand = Hand(); 
    playerType = n; 

    //human
    if(playerType == 0) 
    {
        //get and store name
        cout << "Enter your name: ";
        cin >> name;
    } 

    //playerType != 0 implies robot
    else 
    {
        //create computer player, give name HAL
        cout << "Creating computer player... " << endl;
        cout << "H E L L O !" << endl;
        name = "HAL";
    }
}

/*******************************************************
 * Function: Player::Player(const Player & newPlayer)
 * Description: Player copy constructor
 * Parameters: onst Player & newPlayer - player object to copy
 * Pre-Conditions: none
 * Post-Conditions: Player is made idential to newPlayer
 *******************************************************/
Player::Player(const Player & newPlayer)
{
    //just copy them over. Easy.
    hand = newPlayer.hand;
    name = newPlayer.name;
}

/*******************************************************
 * Function: Player & Player::operator=(const Player & oldPlayer)
 * Description: Player operator= overload
 * Parameters: const Player & oldPlayer
 * Pre-Conditions: oldPlayer cannot be null
 * Post-Conditions: calling player is overwritten by called
 *******************************************************/
Player & Player::operator=(const Player & oldPlayer)
{
    //copy them over
    hand = oldPlayer.hand; 
    name = oldPlayer.name;

    //return pointer to self
    return *this; 
}

/*******************************************************
 * Function: Player::~Player()
 * Description: Player class destructor
 * Parameters: none
 * Pre-Conditions: game has ended
 * Post-Conditions: player object is deleted
 *******************************************************/
Player::~Player() {}

/*******************************************************
 * Function: Hand Player::getHand()
 * Description: returns Player's hand
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none, player state unchanged
 *******************************************************/
Hand Player::getHand() { return hand; } 

/*******************************************************
 * Function: string Player::getName()
 * Description: returns the name of the player
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none, player state unchanged
 *******************************************************/
string Player::getName() { return name; }

/*******************************************************
 * Function: int Player::getPlayerType()
 * Description: returns the type of the player
 * Parameters: none
 * Pre-Conditions: player cannot be null type, but that
 *                 should never happen
 * Post-Conditions: none
 *******************************************************/
int Player::getPlayerType() { return playerType; }

/*******************************************************
 * Function: void Player::addToHand(Card newCard)
 * Description: adds card to the hand of the player
 * Parameters: Card newCard - the card to add to the hand
 * Pre-Conditions: none
 * Post-Conditions: newCard is added to player's hand
 * Note: essentially just passes the card down
 *******************************************************/
void Player::addToHand(Card newCard) { hand.addToCards(newCard); }

/*******************************************************
 * Function: Card Player::drawCardFromIndex(int index)
 * Description: draws card at given index from player's hand
 * Parameters: int index - index of card to draw
 * Pre-Conditions: index must be valid index in hand
 * Post-Conditions: card at index it removed and returned to
 *                  calling function.
 *******************************************************/
Card Player::drawCardFromIndex(int index) { return hand.drawCardFromIndex(index); }

/*******************************************************
 * Function: void Player::printHand()
 * Description: prints the player's hand
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none, player state unchanged
 *******************************************************/
void Player::printHand() { hand.printHand(); }

/*******************************************************
 * Function: bool Player::hasValidCard(Card checkCard)
 * Description: checks if player has card to play for given
 *              checkCard in their hand
 * Parameters: Card checkCard - card to check against
 * Pre-Conditions: none
 * Post-Conditions: none
 * Note: essentially pipes argument down into next object
 *******************************************************/
bool Player::hasValidCard(Card checkCard) { return hand.hasCardOr8(checkCard); }

/*******************************************************
 * Function: bool Player::cardAtIndexCanCover(int index, Card pileCard)
 * Description: checks if card at given index can cover 
 *              pileCard
 * Parameters: int index - index of card to check
 *             Card pileCard - Card which we want to cover
 * Pre-Conditions: index must be within range of hand size
 * Post-Conditions: none, player state remains unchanged
 *******************************************************/
bool Player::cardAtIndexCanCover(int index, Card pileCard) { return hand.cardAtIndexCanCover(index, pileCard); }

/*******************************************************
 * Function: int Player::findMatchIndex(Card pileCard)
 * Description: finds index of card which can cover pileCard
 * Parameters: Card pileCard - pile card we want to find a cover for
 * Pre-Conditions: pileCard is card we want to check, and the hand
 *                 must have a valid card in it
 * Post-Conditions: none, player state remains unchanged
 *******************************************************/
int Player::findMatchIndex(Card pileCard) { return hand.findMatchIndex(pileCard); }