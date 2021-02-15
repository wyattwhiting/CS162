/******************************************************
** Program file: Game.cpp
** Author: Wyatt Whiting
** Date: 2020-10-24
** Description: Implmentation file for Game class
** Input: none at large
** Output: none at large
******************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

/*******************************************************
 * Function: Game::Game()
 * Description: Initializes Game with initial values 
 * Parameters: none
 * Pre-Conditions: User wants to run the game
 * Post-Conditions: Deck has 52 - (7 * 2) - 1 cards and shuffled,
 *                  each player has 7 random cards in hand,
 *                  and pile has been started.
 *******************************************************/
Game::Game()
{
    //populate deck with 52 cards
    stock = Deck();

    //create players
    players[0] = Player(0); 
    players[1] = Player(1); 

    //shuffle the deck
    stock.shuffle(); 

    //deal 7 cards to each player
    for(int i = 0; i < 7; i++) 
    {
        players[0].addToHand(stock.drawTopCard());
        players[1].addToHand(stock.drawTopCard());
    }

    //start stock with card from deck
    pileCard = stock.drawTopCard(); 
}

/*******************************************************
 * Function: Game::~Game()
 * Description: Game object destructor
 * Parameters: none 
 * Pre-Conditions: game has ended
 * Post-Conditions: game is deleted
 *******************************************************/
Game::~Game() {}

/*******************************************************
 * Function: Game::getCards();
 * Description: returns stock Deck object
 * Parameters: none
 * Pre-Conditions: stock has been initialized
 * Post-Conditions: game state unchanged
 *******************************************************/
Deck Game::getCards() { return stock; }

/*******************************************************
 * Function: Game::getPlayer(int index)
 * Description: returns the player at a given index
 * Parameters: int index - indicates which player to return
 * Pre-Conditions: Player members have been initialized
 * Post-Conditions: game state unchanged
 *******************************************************/
Player Game::getPlayer(int index) { return players[index]; }

/*******************************************************
 * Function: Game::getPileCard()
 * Description: returns the current card on top of the pile
 * Parameters: none
 * Pre-Conditions: Pile card must be initialized
 * Post-Conditions: game state unchanged
 *******************************************************/
Card Game::getPileCard() { return pileCard; }

/*******************************************************
 * Function: Game::gameShouldLoop
 * Description: returns indication if main game loop should continue
 * Parameters: none
 * Pre-Conditions: Game should be initialized
 * Post-Conditions: game state unchanged
 *******************************************************/
bool Game::gameShouldLoop()
{
    //variables to make everything more readable
    bool minOnePlayerHasMove = (players[0].hasValidCard(pileCard) && players[0].hasValidCard(pileCard));
    bool cardsInStock = (stock.getNumCards() != 0);

    //test condition for when the game should loop
    return minOnePlayerHasMove || (!minOnePlayerHasMove && cardsInStock);
}

/*******************************************************
 * Function: Game::playGame()
 * Description: main function to play the game
 * Parameters: none
 * Pre-Conditions: game should be initialized but not begun
 * Post-Conditions: game has ended
 *******************************************************/
void Game::playGame()
{
    //while game is in a state where players should still take turns
    while(gameShouldLoop()) 
    {
        //if the computer has played last card, end game
        if(players[1].getHand().getNumCards() == 0) break; 

        //let the human take their turn
        humanTurn(); 

        //if the human is out of cards, end the game
        if(players[0].getHand().getNumCards() == 0) break;

        //let the computer take their turn
        computerTurn(); 
    }

    //print banner
    cout << "---===<: GAME OVER :>===---" << endl; 

    //show the winner of the game
    showWinner(); 
}

/*******************************************************
 * Function: Game::humanTurn()
 * Description: runs the player's turn
 * Parameters: none
 * Pre-Conditions: will run only if game is in non-endgame state
 * Post-Conditions: either quits prematurely if no moves are possible, 
 *                  but when one is, a new card is placed onto the pile 
 *                  and removed from the player's hand
 *******************************************************/
void Game::humanTurn()
{   
    string str;

    //show top card and player's hand
    playerTurnIntro();

    //while player has no valid card
    while(!players[0].hasValidCard(pileCard)) 
    {
        //if there are none to draw
        if(stock.getNumCards() == 0) 
        {
            //tell user and quit
            cout << "You have no moves remaining. Enter any character to continue: ";
            cin >> str;
            return;
        }
        //otherwise, there is one possible to draw
        else 
        {
            //tell user they have to draw card, draw, and print out new hand
            cout << "You have no cards to play. Enter any character to draw from stock: ";
            cin >> str;
            players[0].addToHand(stock.drawTopCard());
            cout << "---===<: Your Hand :>===---" << endl;
            players[0].printHand();
        }
    }

    //if here, card has been validated
    humanTurnHelper();
}

/*******************************************************
 * Function: Game::humanTurnHelper()
 * Description: when player has a valid card in their hand,
 *              this function allows them to pick which card
 *              from their hand to play.
 * Parameters: none
 * Pre-Conditions: game must be in non-endgame state and
 *                 the human must have a valid card in their hand
 * Post-Conditions: card is removed from the human player's hand
 *                  and placed on top of the pile.
 *******************************************************/
void Game::humanTurnHelper()
{
    //variables
    int index;
    bool cardValid = false;

    //while card has not been validated
    while(!cardValid)
    {
        //set index to impossible value to ensure it gets set to a possible one
        index = -1; 

        //while index is outside valid range
        while(index < 0 || index > players[0].getHand().getNumCards() - 1) 
        {   
            //prompt for input and store
            cout << "Please enter the index of the card you'd like to play: ";
            cin.clear();
            cin >> index;
        }

        //input is in valid 
        if(players[0].cardAtIndexCanCover(index, pileCard)) cardValid = true; 
    }

    //index is for valid card, so replace the pile card with the card drawn from position 'index'
    pileCard = players[0].drawCardFromIndex(index); 
    if(pileCard.getRank() == 8) pileCard = playerFix8();
}

/*******************************************************
 * Function: playerTurnIntro()
 * Description: prints the header when the player's turn begins
 * Parameters: none
 * Pre-Conditions: gamestate must allow the huamn to take a turn
 * Post-Conditions: gamestate remains unchanged
 *******************************************************/
void Game::playerTurnIntro()
{
    //print out some gamestate info
    cout << "---===<: Your Turn :>===---" << endl;
    cout << "---===<: Top of Pile :>===--- " << endl;
    cout << pileCard.toString() << endl;
    cout << endl;
    cout << "---===<: Your Hand :>===--- " << endl;
    players[0].printHand();
}

/*******************************************************
 * Function: Game::playerFix8()
 * Description: fixes the 8 when played, allowing player to 
 *              specify a new suit
 * Parameters: none
 * Pre-Conditions: player has played an 8
 * Post-Conditions: returns card with rank 8 and suit of 
 *                  player choice
 *******************************************************/
Card Game::playerFix8()
{
    //initiate user choice and suit array
    int userChoice = -1; 
    string suitArr[] = {"diamond", "heart", "club", "spade"}; 
    cout << "Please select a suit for the computer to match: " << endl; 

    //print options
    for(int i = 0; i < 4; i++)
    {
        cout << i << ": " << suitArr[i] << endl;
    }

    //take user input at least once
    do 
    {
        //take user choice
        cin >> userChoice;
    } while (userChoice < 0 || userChoice > 3); 

    //return card with selected suit
    return Card(8, userChoice + 1); 
}

/*******************************************************
 * Function: Game::computerTurn()
 * Description: runs the computer's turn in the game
 * Parameters: none
 * Pre-Conditions: game must be in non-end state
 * Post-Conditions: updates gamestate in accordance with the
 *                  rules of Crazy 8
 *******************************************************/
void Game::computerTurn()
{
    //print banner stuff
    computerTurnIntro(); 

    //computer reports how many cards they have in their hand
    cout << "I  H A V E  " << players[1].getHand().getNumCards() << "  C A R D S  I N  M Y  H A N D" << endl;

    //while player has no valid card
    while(!players[1].hasValidCard(pileCard)) 
    {
        //if there are none to draw
        if(stock.getNumCards() == 0) 
        {
            //computer says it has no more moves, ends turn
            cout << "I  A M  O U T  O F  M O V E S .  E N D I N G  T U R N ." << endl;
            return;
        }
        else
        {
            //computer says it must draw a card, reports how many it has now
            cout << "I  H A V E  N O  M A T C H I N G  C A R D S .  D R A W I N G  N O W ." << endl;
            players[1].addToHand(stock.drawTopCard());
            cout << "I  N O W  H A V E  " << players[1].getHand().getNumCards() << "  C A R D S ." << endl;
            
        }
    }

    //if program gets here, move may continue safely 
    computerTurnHelper();
}

/*******************************************************
 * Function: Game::computerTurnHelper()
 * Description: when player may play a card on their turn,
 *              gets the card for the computer to play
 * Parameters: none
 * Pre-Conditions: within the computer's turn, it must have 
 *                 a card in its hand that may be played
 * Post-Conditions: new card is placed on pile from the computer's 
 *                  hand
 *******************************************************/
void Game::computerTurnHelper()
{
    //some variables
    int index;
    bool cardValid = false; 

    //while the card at index has not been validated
    while(!cardValid)
    {
        //start with impossible value
        index = -1;

        //while outside range
        while(index < 0 || index > players[1].getHand().getNumCards() - 1) 
        {   
            //find card to play, report which one it is
            index = players[1].findMatchIndex(pileCard);
            cout << "I  A M  P L A Y I N G  C A R D  A T  I N D E X  " << index << ": ";
            cout << players[1].getHand().getCard(index).toString() << endl;
        }

        //catch error
        if(index == -1) 
        {
            cout << "ERROR" << endl;
            return;
        }

        //check if card is valid to place on pile
        if(players[1].cardAtIndexCanCover(index, pileCard)) cardValid = true; 
    }

    //draw card from position 'index' from hand, place on pile
    pileCard = players[1].drawCardFromIndex(index); 

    //if 8 was played, pick random suit for player to match
    if(pileCard.getRank() == 8) pileCard = computerFix8();
}

/*******************************************************
 * Function: Game::computerTurnIntro()
 * Description: prints the header for the computer's turn
 * Parameters: none
 * Pre-Conditions: computer player can begin their turn
 * Post-Conditions: gamestate remains unchanged
 *******************************************************/
void Game::computerTurnIntro()
{
    //print banner and card on top of pile
    cout << "---===<: Computer Turn :>===---" << endl;
    cout << "---===<: Top of Pile :>===---" << endl;
    cout << pileCard.toString() << endl;
    cout << endl;
}

/*******************************************************
 * Function: Game::computerFix8()
 * Description: allows computer player to choose a new suit
 *              after playing 8.
 * Parameters: none
 * Pre-Conditions:  computer has played an 8
 * Post-Conditions: returns card of rank 8 and suit     
 *                  chosen by the computer.
 *******************************************************/
Card Game::computerFix8()
{
    //tell player an 8 has been played
    cout << "I  J U S T  P L A Y E D  A N  8 . " << endl; 

    string suitArr[] = {"D I A M O N D", "H E A R T", "C L U B", "S P A D E"}; 

    //seed random time
    srand(time(NULL));
    int suitNum = (rand() % 4);

    //announce which rank has been chosen
    cout << "I  A M  S E L E C T I N G  R A N K  " << suitArr[suitNum] << " ." << endl; 

    //return card with rank 8 and suit (suitNum + 1)
    return Card(8, suitNum + 1); 
}

/*******************************************************
 * Function: Game::showWinner()
 * Description: displays the winner of the game
 * Parameters: none
 * Pre-Conditions: game is in endstate
 * Post-Conditions: gamestate remains in endstate
 *******************************************************/
void Game::showWinner()
{
    //buckets for numbers of cards in each hand
    int humanCards = players[0].getHand().getNumCards();
    int computerCards = players[1].getHand().getNumCards();

    //if human has no cards
    if(humanCards == 0 || humanCards < computerCards) 
    {
        //print player name
        cout << players[0].getName(); 
    }

    //if computer has no cards
    else if(computerCards == 0 || computerCards < humanCards) 
    {
        //print computer name
        cout << players[1].getName(); 
    }
    else
    {
        cout << "ERROR! You messed up, dummy." << endl;
    }

    //finish the message
    cout << " has won the game!" << endl; 
}