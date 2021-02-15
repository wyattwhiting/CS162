#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Card 
{
    private: 
        int rank;
        int suit;
    public:
        //constructors
        Card();
        Card(int, int);
        Card(const Card &);
        Card & operator=(const Card &);

        //destructors
        ~Card();

        //getters
        int getRank();
        int getSuit();
        string toString();

        //setters
        void setRank(int);
        void setSuit(int);

        
};

#endif