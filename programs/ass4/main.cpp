/******************************************************
** File: Room.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Room implementation file
******************************************************/

#include "MasterInclude.h"

/*******************************************************
 * Function: bool playAgain()
 * Description: asks if player wants to play again and returns indicator of answer
 * Parameters: none
 * Pre-Conditions: game has ran once
 * Post-Conditions: returns player choice
 *******************************************************/
bool playAgain()
{
    char in = ' ';
    do 
    { 
        cout << endl << "Would you like to play again? (y/n): ";
        cin >> in;
    } while(in != 'y' && in != 'n');

    return in == 'y';
}

/*******************************************************
 * Function: int main(int argc, char ** argv)
 * Description: main function
 * Parameters: int argc - number of command line arguments
 * Pre-Conditions: game not started
 * Post-Conditions: game has ended and program terminates
 *******************************************************/
int main(int argc, char ** argv)
{
    do
    {
        //initialize game object
        Game game = Game(argv[1], argv[2]); //initialize game

        game.play(); //play the game
        //will add looping later
    } while(playAgain());

    return 0;
}