/******************************************************
** File: Node.cpp
** Author: Wyatt Whiting
** Date: 2020-12-02
** Description: Node implementation file
******************************************************/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "Node.h"

using namespace std;

/*******************************************************
 * Function: Node::Node(int val)
 * Description: Node constructor
 * Parameters: int val - value for the node
 * Pre-Conditions: node does not exist
 * Post-Conditions: node exists with NULL next pointer
 *******************************************************/
Node::Node(int val) //adding node to end
{
    this->val = val;
    this->next = NULL;
}

/*******************************************************
 * Function: Node::Node(int val, Node * ptr)
 * Description: Overloaded node constructor 
 * Parameters: int val - value for the node
 *             Node * ptr - pointer to next element for 
 * Pre-Conditions: node does not exist
 * Post-Conditions: Node exists with data 'val' and pointer 'ptr'
 *******************************************************/
Node::Node(int val, Node * ptr)
{
    this->val = val;
    this->next = ptr;
}

/*******************************************************
 * Function: Node::~Node()
 * Description: node destructor
 * Parameters: none
 * Pre-Conditions: node exists
 * Post-Conditions: node no longer exists
 *******************************************************/
Node::~Node() {};