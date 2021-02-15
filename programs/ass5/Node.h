/******************************************************
** File: Node.h
** Author: Wyatt Whiting
** Date: 2020-12-02
** Description: Node header file
******************************************************/

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
    public:
        int val;
        Node * next;

        Node();
        Node(int);
        Node(int, Node *);
        ~Node();
};

#endif