/******************************************************
** File: LinkedList.h
** Author: Wyatt Whiting
** Date: 2020-12-02
** Description: linked list header file
******************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

class LinkedList
{
    private:
        unsigned int length;
        Node * head;

    public:
        LinkedList();
        ~LinkedList();
        
        int getLength();
        void print();
        void clear();

        unsigned int pushFront(int);
        unsigned int pushBack(int);
        unsigned int insert(int, unsigned int);

        void sortAscending();
        void sortDescending();

        void mergeSort(Node **, bool);
        void split(Node**, Node**, Node *);
        Node * mergeLists(Node *, Node*, bool);

        bool isPrime(unsigned int);
        int countPrimes();
};

#endif