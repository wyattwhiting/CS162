/******************************************************
** File: main.cpp
** Author: Wyatt Whiting
** Date: 2020-11-01
** Description: client-facing code for Zoo Tycoon
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Zoo.h"

/*******************************************************
 * Function: int main()
 * Description: main function for running game
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: game is played, memory cleaned up
 *******************************************************/
int main()
{
    //make zoo
    Zoo myZoo;

    //play game
    myZoo.play();

    //return 0, quit
    return 0;
}