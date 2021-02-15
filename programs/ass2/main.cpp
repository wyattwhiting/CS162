#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

void playGame()
{
    cout << "Starting game..." << endl;

    //game constructor populates and shuffles the deck, creates players,
    //deals 7 to each player
    Game crazy8;
    Card topCard;
    crazy8.startGame();
    topCard = crazy8.flipTopCard();
    cout << "Top Card: " << topCard.toString() << endl;

    while(crazy8.getCards().getNumCards() != 0) 
    {
        crazy8.printHumanHand(); //print player's

        while(!crazy8.playerHasValidCard(0, topCard) && crazy8.getCards().getNumCards() != 0)
        {
            int lmao;
            cout << "You don't have a card. Press enter to draw from the deck.";
            cin >> lmao;
            crazy8.playerDrawCard(0);
            crazy8.printHumanHand();

        }

        if(crazy8.playerHasValidCard(0, topCard) && crazy8.getCards().getNumCards() != 0) //if human has card to play
        {
            cout << "player has valid card!" << endl; //diagnostics

            //get new top card, making sure it's valid for the given top card
            Card newTopCard = crazy8.getHumanCard(topCard); //new temp card, must return card that can take over topCard
            
            if(newTopCard.getRank() == 8) //if player selected an 8
            {
                int newSuit = 0; //null suit
                while(newSuit < 1 && newSuit > 4) //as long as input is outside range
                {   
                    //prompt for new suit and take
                    cout << "Please specify a suit: 1 = diamond, 2 = heart, 3 = club, 4 = spade";
                    cin >> newSuit;
                }
                newTopCard.setSuit(newSuit); //set validated suit to new top card
            }
            topCard = newTopCard; //overwrite top card
        }

        cout << "Top Card: " << topCard.toString() << endl;

        while(!crazy8.playerHasValidCard(1, topCard) && crazy8.getCards().getNumCards() != 0)
        {
            cout << "D A R N  I T. I  D O  N O T  H A V E  A  C A R D.  D R A W I N G  N O W." << endl;
            crazy8.playerDrawCard(1);
        }

        if(crazy8.playerHasValidCard(1, topCard) && crazy8.getCards().getNumCards() != 0)
        {
            crazy8.printComputerHand();
            cout << "computer has valid card" << endl;
        }
        break;
    }


    //straight into game loop


    //return 0 and exit program
    cout << "Ending game..." << endl;
}

int main() {
    playGame();

    return 0;
}