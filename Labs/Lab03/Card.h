#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Card {
    public:
        //constructors
        Card();
        Card(string, int);

        //setters
        void setSuit(string);
        void setRank(int);

        //getters
        string getSuit();
        int getRank();

    private:
        string suit;
        int rank;
};


#endif