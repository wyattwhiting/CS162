/******************************************************
** File: Game.cpp
** Author: Wyatt Whiting
** Date: 2020-11-19
** Description: Game implementation file
******************************************************/

#include "MasterInclude.h"
#include <stdio.h>

/*******************************************************
 * Function: Game::Game() 
 * Description: defualt game constructor
 * Parameters: none
 * Pre-Conditions: game does not exist
 * Post-Conditions: game exists
 * Note: should never be called
 *******************************************************/
Game::Game() 
{
    //should never be called
    playerPos[0] = 0;
    playerPos[1] = 0;
    debug = true;
}

/*******************************************************
 * Function: Game::Game(char * arg1, char * arg2)
 * Description: overloaded game constructor
 * Parameters: char * arg1 - pointer to dimension
 *             char * arg2 - pointer to cstring of debug
 * Pre-Conditions: game does not exist
 * Post-Conditions: game exists
 *******************************************************/
Game::Game(char * arg1, char * arg2)
{
    srand(time(NULL)); //seed rng
    int dim = (*arg1) - '0'; //convert char to int
    if(dim < 4) dim = 4; //minimum size
    char trueStr[] = "true"; //cstring for comparison

    //player starts alive with three arrows
    playerIsAlive = true;
    playerHasGold = false;
    arrows = 3;

    //initialize positions
    playerPos[0] = playerPos[1] = 0;
    ropePos[0] = ropePos[1] = 0;
    arrowPos[0] = arrowPos[1] = 0;

    this->debug = false; //default is debug off
    if(!strcmp(arg2, trueStr)) this->debug = true; //if true is specified, set debug as such

    //initialize room to be square with side length dim
    map.resize(dim, vector<Room>(dim, Room())); 
    
    //popoulate map with player and events
    this->populateEvents();
    this->playerInit();
}

/*******************************************************
 * Function: Game::~Game()
 * Description: game destructor
 * Parameters: none
 * Pre-Conditions: game exists 
 * Post-Conditions: game no longer exists
 *******************************************************/
Game::~Game() {}

/*******************************************************
 * Function: void Game::randomize(int & int1, int & int2)
 * Description: randomizes int to range [0, mapsize]
 * Parameters: int & int1 - first integer to randomize
 *             int * int2 - second integer to randomize
 * Pre-Conditions: argumentsmnts have some value
 * Post-Conditions: arguments each assume new random value
 *******************************************************/
void Game::randomize(int & int1, int & int2)
{
    //assign the integers new values limited by map dimenions
    int1 = rand() % map.size();
    int2 = rand() % map.size();
}

/*******************************************************
 * Function: void Game::checkPercepts()
 * Description: checks the percepts for rooms surrounding player
 * Parameters: none
 * Pre-Conditions: none in particular
 * Post-Conditions: all valid room percepts are called
 *******************************************************/
void Game::checkPercepts()
{
    //save as local variables to cut down on syntax length
    int row = playerPos[0];
    int col = playerPos[1];
    int mapSize = map.size();

    //as long as the rooms exist, percept the room *POLYMORPHISM HERE*
    if(row != 0) map[row - 1][col].roomPercept();
    if(row != mapSize - 1) map[row + 1][col].roomPercept();
    if(col != 0) map[row][col - 1].roomPercept();
    if(col != mapSize - 1) map[row][col + 1].roomPercept();
}

/*******************************************************
 * Function: bool Game::isInBounds(int r, int c)
 * Description: checks if integers are within bounds of map
 * Parameters: int r - row value to check
 *             int c - column value to check
 * Pre-Conditions: arguments have coordinates to check
 * Post-Conditions: none, gamestate remains unchanged
 *******************************************************/
bool Game::isInBounds(int r, int c)
{
    //if outside valid bounds, return false
    if(r < 0 || r >= map.size()) return false;
    if(c < 0 || c >= map.size()) return false;

    //otherwise, return true
    return true;
}

/*******************************************************
 * Function: void Game::printAddlInfo()
 * Description: prints controls and arrow count for player
 * Parameters: none
 * Pre-Conditions: game and map are initialized
 * Post-Conditions: relavant info printed to screen
 *******************************************************/
void Game::printAddlInfo()
{
    //just some simple printing of info for player
    cout << "Movement: WASD        Shoot Arrow: IJKL" << endl;
    cout << "Arrows Remaining: " << arrows << "  |  " << "Gold: " << playerHasGold << endl;
}

/*******************************************************
 * Function: void Game::printMap()
 * Description: prints the game map
 * Parameters: none
 * Pre-Conditions: board must be instantiated and populated
 * Post-Conditions: prints gamestate to screen, nothing is changed
 *******************************************************/
void Game::printMap()
{
    int dim = map.size(); //how many cells to print   
    cout << endl; //formatting
    printAddlInfo();

    //loop through rows
    for(int i = 0; i < dim; i++)
    {   
        //horizontal line, cap with an extra '+'
        for(int j = 0; j < dim; j++) cout << "+---";
        cout << '+' << endl;

        //loop through columns
        for(int j = 0; j < dim; j++)
        {
            //first edge of wall
            cout << "| ";

            //if current room check is player's location
            if(i == playerPos[0] && j == playerPos[1])
            {   
                //print green '@'
                cout << "\033[32m";
                cout << '@';
                cout << "\u001b[37m";
            } 

            else if(i == ropePos[0] && j == ropePos[1] && debug) cout << 'R';
            //if in debug mode, print the event characters
            else if(debug) cout << map[i][j].getEventChar();

            //otherwise, just print a space
            else cout << ' ';

            //always pring this space for alignment
            cout << ' ';
        } 
        
        //cap off with wall
        cout << '|' << endl;
    }

    //print bottom wall and return 
    cout << '+';
    for(int i = 0; i < dim; i++) cout << "---+";
    cout << endl;
}

/*******************************************************
 * Function: void Game::populateEvents()
 * Description: randomly places events into the map
 * Parameters: none
 * Pre-Conditions: 2d room array must be initialized with dimension >= 4
 * Post-Conditions: required events are randomly placed into the room
 *******************************************************/
void Game::populateEvents()
{
    //coordinates for later use
    int coord1, coord2;

    //vector of Event pointers for adding into map
    vector<Event *> events = { new Bats(), new Bats(), 
                               new Pit(),  new Pit(),
                               new Wumpus(), new Gold() };

    //as long as there are still items to add to the map
    while(events.size() != 0)
    {
        //randomize coordinates 
        randomize(coord1, coord2);

        //if an empty room
        if(map[coord1][coord2].isEmpty())
        {
            //set room event with end element from event array and remove it
            map[coord1][coord2].setEvent(events.back());
            events.pop_back();
        }
    }
}

/*******************************************************
 * Function: void Game::playerInit()
 * Description: initializes a player into a random non-emtpy room on the board
 * Parameters: none
 * Pre-Conditions: 2d room array should be populated with events
 * Post-Conditions: player location is initailized
 *******************************************************/
void Game::playerInit()
{
    int r, c; //row and column for readability
    do
    {   
        //randomize coordinates until empty room is found
        randomize(r, c);

    } while (!map[r][c].isEmpty());    

    //set player coordinates to empty room
    playerPos[0] = ropePos[0] = r;
    playerPos[1] = ropePos[1] = c;
}

/*******************************************************
 * Function: void Game::moveToNewRoom()
 * Description: moves player to random non-empty room
 * Parameters: none
 * Pre-Conditions: player has encountered a bat room
 * Post-Conditions: player is moved into random non-empty room
 *******************************************************/
void Game::moveToNewRoom()
{
    int r, c; //row and column for readability
    do
    {   
        //randomize coordinates until empty room is found
        randomize(r, c);

    } while (!map[r][c].isEmpty());    

    //set player coordinates to empty room
    playerPos[0] = r;
    playerPos[1] = c;
}

/*******************************************************
 * Function: char Game::getInput()
 * Description: gets and returns validated input from user
 * Parameters: none
 * Pre-Conditions: game should be expecting user input
 * Post-Conditions: returns validated input but does not change gamestate
 *******************************************************/
char Game::getInput()
{
    //input bucket and validity flag
    char in;
    bool valid = false;

    //allow raw input
    system("stty raw");
    do
    {   
        //get input and check its acceptable until one is entered
        in = getchar();
        if(in == 'w' || in == 'a' || in == 's' || in == 'd') valid = true;
        if(in == 'i' || in == 'j' || in == 'k' || in == 'l') valid = true;
    } while (!valid);

    //return to standard input and return validated character
    system("stty cooked");
    return in;
}

/*******************************************************
 * Function: void Game::fireArrow(char in)
 * Description: fires arrow based on inputted direction
 * Parameters: char in - input from player
 * Pre-Conditions: player turn is active
 * Post-Conditions: arrow is fired. Removes wumpus if hit
 *******************************************************/
void Game::fireArrow(char in)
{
    //setting up coordinates
    int dr, dc;
    arrowPos[0] = playerPos[0];
    arrowPos[1] = playerPos[1];

    //remove arrow from inventory
    arrows--; 

    //translate input into net change of coordinates
    if(in == 'i'){ dr = -1; dc =  0; }
    if(in == 'k'){ dr =  1; dc =  0; }
    if(in == 'j'){ dr =  0; dc = -1; }
    if(in == 'l'){ dr =  0; dc =  1; }

    //hit flag
    bool wumpusHit = false;

    //let the arrow fly for 3 rooms
    for(int i = 0; i < 3; i++)
    {
        //if upcoming arrow location is a valid room
        if(isInBounds(arrowPos[0] + dr, arrowPos[1] + dc)) 
        {
            //update arrow postion
            arrowPos[0] += dr;
            arrowPos[1] += dc;

            //check if wumpus was hit in that room
            map[arrowPos[0]][arrowPos[1]].checkWumpus(wumpusHit);
        }
    }

    //P(move wumpus) = 3/4
    if(!wumpusHit && rand() % 4 != 0) moveWumpus(); 
}

/*******************************************************
 * Function: void Game::moveWumpus()
 * Description: moves wumpus to random non-empty room
 * Parameters: none
 * Pre-Conditions: Wumpus has been awoken by an arrow
 * Post-Conditions: wumpus assumes new position on map
 *******************************************************/
void Game::moveWumpus()
{
    //tell the player the Wumpus moved
    cout << "Your arrow has awoken the Wumpus. It moved to a new room." << endl;

    //loop through rows
    for(int i = 0; i < map.size(); i++)
    {
        //loop through columns
        for(int j = 0; j < map.size(); j++)
        {
            //if wumpus, delete
            if(map[i][j].getEventChar() == 'W') map[i][j].deleteEvent();
        }
    }

    //new row and columns
    int r, c; //row and column for readability
    do
    {   
        //randomize coordinates until empty room is found
        randomize(r, c);

    } while (!map[r][c].isEmpty());    

    //set new Wumpus in empty room
    map[r][c].setEvent(new Wumpus());
}

/*******************************************************
 * Function: void Game::playerMove()
 * Description: takes and coordinates player's turn
 * Parameters: none
 * Pre-Conditions: game and map are fully instantiated
 * Post-Conditions: player location is updated or arrow is fired
 *******************************************************/
void Game::playerMove()
{
    //input character
    char in = getInput();
    cout << endl;

    //map movement
    if(in == 'w' && playerPos[0] != 0) playerPos[0] -= 1;
    else if(in == 's' && playerPos[0] != map.size() - 1) playerPos[0] += 1;
    else if(in == 'a' && playerPos[1] != 0) playerPos[1] -= 1;
    else if(in == 'd' && playerPos[1] != map.size() - 1) playerPos[1] += 1; 

    //shooting arrow
    else fireArrow(in); 
}

/*******************************************************
 * Function: void Game::roomInteract()
 * Description: interacts with room the player is in
 * Parameters: none
 * Pre-Conditions: player is in a room
 * Post-Conditions: updates gamestate based on type of room event
 *******************************************************/
void Game::roomInteract()
{
    //interact with the room
    char c = map[playerPos[0]][playerPos[1]].getEventChar();
    map[playerPos[0]][playerPos[1]].interact(); //*POLYMORPHISM HERE*

    //change gamestate in accordance with game rules
    if(c == 'W') playerIsAlive = false; 
    if(c == 'B') moveToNewRoom();
    if(c == 'P') playerIsAlive = false;
    if(c == 'G') playerHasGold = true;
}

/*******************************************************
 * Function: bool Game::gameOver()
 * Description: determines if game is in endstate
 * Parameters: none
 * Pre-Conditions: game is initialized
 * Post-Conditions: gamestate is unchanged, returns indicator
 *******************************************************/
bool Game::gameOver()
{   
    //stores if player is at the escape rope position
    bool atRope = (playerPos[0] == ropePos[0]) && (playerPos[1] == ropePos[1]);

    //if they're deadl, it's always over
    if(!playerIsAlive) return true;

    //should be self-explanatory
    return playerHasGold && atRope;
}

/*******************************************************
 * Function: void Game::play()
 * Description: plays the game
 * Parameters: none
 * Pre-Conditions: game has not started
 * Post-Conditions: game has ended
 *******************************************************/
void Game::play()
{
    //play game while it's not in an endstate
    do
    {
        //carry out the game procedures
        this->printMap();
        this->checkPercepts();
        this->playerMove();

        //print new lines for readability
        for(int i = 0; i < 5; i++) cout << endl;

        //interact with the room player is in
        this->roomInteract();
        
    } while(!gameOver());

    //tell player game is over
    cout << "Game over! ";

    //If player got gold, congratulate them.
    if(playerHasGold && playerIsAlive) cout << "You got the gold! Congrats. U did it.";
}