/******************************************************
** File: Game.h
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Game header file
******************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Event.h"
#include "Room.h"

using namespace std;

class Game
{
    private:
        vector< vector<Room> > map;
    
        //variables
        int playerPos[2];       //player coordinates
        int ropePos[2];         //escape rope position. Also stores original player location
        int arrowPos[2];        //arrow position
        int arrows;             //start with 3 arrows
        bool debug;             //debug flag
        bool playerHasGold;     //gold flag
        bool playerIsAlive;

        //functions
        void randomize(int &, int &);
        void checkPercepts();
        bool isInBounds(int, int);
        void printAddlInfo();
        void printMap();
        void populateEvents();
        void playerInit();
        void moveToNewRoom();
        char getInput();
        void fireArrow(char);
        void moveWumpus();
        void playerMove();
        void roomInteract();
        bool gameOver();
        
    public:
        //constructors and destructor
        Game();
        Game(char *, char *); 
        Game(const Game&);
        ~Game();

        //operator overload
        Game & operator=(const Game &);

        //only public function
        void play();
};

#endif