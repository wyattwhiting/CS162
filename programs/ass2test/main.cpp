/******************************************************
** Program: main.cpp - Crazy 8 Game
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: Plays a full game of Crazy 8s against a human player.
**              Prints out all relevant input and output. Loops if
**              the player wants to continue. 
** Input: Takes user prompts for card input, etc.
** Output: Shows gamestate after each turn and guides player through the game
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

/*******************************************************
 * Function: int main()
 * Description: main function
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 *******************************************************/
int main()
{   
    //default want to replay
    int playAgain = 1; //default yes

    //run game at least once
    do 
    {   
        //print game is starting
        cout << "Starting game..." << endl; 

        //starts game with two players, hands with 7 cards each
        Game crazy8; 

        //play game to completion
        crazy8.playGame(); 

        //prompt for input and take
        cout << "Would you like to play again? (0 = no, anything else = yes): ";
        cin >> playAgain;
    } while (playAgain != 0);
    
    //return 0 and exit program
    return 0;
}